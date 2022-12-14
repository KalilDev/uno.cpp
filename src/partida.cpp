/**
 * @file partida.cpp
 * O arquivo que implementa a classe Partida
 */
#include <string>
#include "partida.hpp"
#include "carta_especial.hpp"
#include "util.hpp"
#include <stdexcept>

DirecaoDaPartida direcaoOposta(DirecaoDaPartida direcao) {
    switch (direcao) {
        case Normal:
            return DirecaoDaPartida::Reversa;
        case Reversa:
            return DirecaoDaPartida::Normal;
        default:
            throw std::invalid_argument("DirecaoDaPartida invalida");
    }
}

NaoESuaVez::NaoESuaVez(id_jogador jogador):_jogador(jogador), _string("Não é a vez do jogador " + std::to_string(jogador)) {
}
const char* NaoESuaVez::what() const noexcept {
    return _string.c_str();
}
CartaInvalida::CartaInvalida(id_jogador jogador, Carta *ultima_carta, Carta *nova_carta):_jogador(jogador),_ultima_carta(ultima_carta),_nova_carta(nova_carta), _string("O Jogador " + std::to_string(jogador) + " não pode jogar a carta " + nova_carta->toString() + " em cima da carta" + ultima_carta->toString()) {

}
const char* CartaInvalida::what() const noexcept {
    return _string.c_str();
}
Partida::Partida() = default;

DirecaoDaPartida Partida::getDirecao() const {
    return _direcao;
}

id_jogador Partida::getJogadorAtual() const {
    return _jogador_atual;
}

void Partida::jogarCarta(id_jogador id_jogador, size_t card_index) noexcept(false) {
    if (id_jogador != getJogadorAtual()) {
        throw NaoESuaVez(id_jogador);
    }
    auto ultima_carta = _cartas_na_mesa.getTop();
    auto &jogador = _jogadores[id_jogador];
    auto nova_carta = (*jogador.getMao())[card_index];
    if (nova_carta->getCor() !=ultima_carta->getCor() && nova_carta->getNumero() != ultima_carta->getNumero()) {
        throw CartaInvalida(id_jogador, ultima_carta, nova_carta);
    }
    _cartas_na_mesa.push(nova_carta);
    jogador.getMao()->removerCarta(card_index);
    auto carta_especial = cast_carta_to_carta_especial(nova_carta);
    if (carta_especial == nullptr) {
        avancarJogador();
        return;
    }
    switch (carta_especial->getTipo()) {
        case Bloqueia:
            avancarJogador();
            avancarJogador();
            return;
        case ComeDois:
            avancarJogador();
            comerUmaCarta();
            comerUmaCarta();
            avancarJogador();
            return;
        case Reverso:
            _direcao = direcaoOposta(_direcao);
            avancarJogador();
            return;
    }


}

CorDaCarta Partida::getCorDaPartida() noexcept(false) {
    return _cartas_na_mesa.getTop()->getCor();
}

void Partida::comerCarta(id_jogador id_jogador) {
    if (id_jogador != getJogadorAtual()) {
        throw NaoESuaVez(id_jogador);
    }
    comerUmaCarta();
    avancarJogador();
}

#define NUM_JOGADORES 4
#define NUM_CARTAS 7

void Partida::iniciarEstado() {
    _cartas_para_comer = Pilha::cheia();
    _cartas_para_comer.random();
    auto carta_inicial = _cartas_para_comer.popPrimeiraNaoEspecial();
    _cartas_na_mesa = {carta_inicial};
    for (id_jogador i = 0; i < NUM_JOGADORES; i++) {
        auto jogador = Jogador{i};
        for (auto j = 0; j < NUM_CARTAS; j++) {
            jogador.getMao()->adicionarCarta(_cartas_para_comer.pop());
        }
        _jogadores.push_back(std::move(jogador));
    }
    _jogador_atual = 0;
    _direcao = DirecaoDaPartida::Normal;
}

void Partida::limparEstado() {
    _jogadores.clear();
    _cartas_na_mesa = {};
    _cartas_para_comer = {};
    _jogador_atual=0;
    _direcao=DirecaoDaPartida::Normal;
}

void Partida::jogarBot() {
    auto &bot = _jogadores[_jogador_atual];
    auto mao = bot.getMao();
    auto cartas_possiveis = std::vector<size_t>{};
    auto carta_atual = _cartas_na_mesa.getTop();
    for (size_t i = 0 ; i < mao->size(); i++) {
        auto carta = (*mao)[i];
        if (carta->getCor() != carta_atual->getCor() && carta->getNumero() != carta_atual->getNumero()) {
            continue;
        }
        cartas_possiveis.push_back(i);
    }
    if (cartas_possiveis.empty()) {
        comerCarta(_jogador_atual);
        return;
    }
    auto i = static_cast<size_t>(random()) % cartas_possiveis.size();
    try {
        jogarCarta(_jogador_atual, i);
    } catch (std::exception&e) {
        comerCarta(_jogador_atual);
    }
}

void Partida::avancarJogador() {
    using id = id_jogador;
    using ll = long long;
    switch (_direcao) {
        case DirecaoDaPartida::Normal:
            _jogador_atual = (_jogador_atual + 1) % _jogadores.size();
            break;
        case DirecaoDaPartida::Reversa:
            _jogador_atual = (id)((ll)_jogadores.size() + (ll)_jogador_atual - 1) % _jogadores.size();
            break;
    }
}

void Partida::comerUmaCarta() {
    auto &jogador = _jogadores[_jogador_atual];
    if (_cartas_para_comer.size() == 1 && _cartas_na_mesa.size() > 1) {
        auto ultima_carta_na_mesa = _cartas_na_mesa.pop();
        for (auto carta = _cartas_na_mesa.pop(); _cartas_na_mesa.size() > 0; carta = _cartas_na_mesa.pop()) {
            _cartas_para_comer.push(carta);
        }
        _cartas_para_comer.random();
        _cartas_na_mesa = {ultima_carta_na_mesa};
    }
    if (_cartas_para_comer.size() == 0) {
        return;
    }
    auto carta = _cartas_para_comer.pop();
    jogador.getMao()->adicionarCarta(carta);
}

int Partida::getVencedor() {
    for (size_t i =0; i < _jogadores.size(); i++) {
        auto &jogador = _jogadores[i];
        if (jogador.getMao()->size() == 0) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

Pilha *Partida::getCartasNaMesa() {
    return &_cartas_na_mesa;
}

Pilha *Partida::getCartasParaComer() {
    return &_cartas_para_comer;
}

Jogador *Partida::begin() {
    return &*_jogadores.begin();
}

Jogador *Partida::end() {
    return &*_jogadores.end();
}

Jogador *Partida::operator[](size_t i) {
    if (i >= _jogadores.size()) {
        throw std::range_error("Indice invalido para jogador");
    }
    return &_jogadores[i];
}

size_t Partida::size() const {
    return _jogadores.size();
}

extern "C" {
    DirecaoDaPartida partida_get_direcao(Partida* self) {
        return self->getDirecao();
    }
    id_jogador partida_get_jogador_atual(Partida* self) {
        return self->getJogadorAtual();
    }
    void partida_jogar_carta(Partida* self,id_jogador id_jogador, size_t card_index, char** e) {
        try {
            *e = nullptr;
            return self->jogarCarta(id_jogador, card_index);
        } catch (const std::exception& exception) {
            exception_to_c(e, exception);
            return;
        }
    }
    CorDaCarta partida_get_cor_da_partida(Partida* self) {
        return self->getCorDaPartida();
    }
    void partida_comer_carta(Partida*self,id_jogador id_jogador, char** e) {
        try {
            *e = nullptr;
            return self->comerCarta(id_jogador);
        } catch (const std::exception& exception) {
            exception_to_c(e, exception);
        }
    }
    void partida_jogar_bot(Partida* self) {
        return self->jogarBot();
    }
    const Pilha *partida_get_cartas_na_mesa(Partida* self) {
        return self->getCartasNaMesa();
    }
    const Pilha *partida_get_cartas_para_comer(Partida* self) {
        return self->getCartasParaComer();
    }
    int partida_get_vencedor(Partida* self) {
        return self->getVencedor();
    }
    size_t partida_size(Partida* self) {
	return self->size();
    }
    Jogador *partida_at(Partida *self, size_t i, char**e) {
        try {
            *e = nullptr;
            return (*self)[i];
        } catch (const std::range_error& exception) {
            exception_to_c(e, exception);
            return nullptr;
        }catch (const NaoESuaVez& exception) {
            exception_to_c(e, exception);
            return nullptr;
        }catch (const CartaInvalida& exception) {
            exception_to_c(e, exception);
            return nullptr;
        }
    }
    Jogador *partida_begin(Partida*self) {
        return self->begin();
    }
    Jogador *partida_end(Partida*self) {
        return self->end();
    }
}
