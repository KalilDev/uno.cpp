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

DirecaoDaPartida Partida::getDirecao() {
    return _direcao;
}

id_jogador Partida::getJogadorAtual() {
    return _jogador_atual;
}

void Partida::jogarCarta(id_jogador id_jogador, size_t card_index) {
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
    auto carta_especial = dynamic_cast<CartaEspecial *>(nova_carta);
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

CorDaCarta Partida::getCorDaPartida() {
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
        _jogadores.push_back(jogador);
        for (auto j = 0; j < NUM_CARTAS; j++) {
            jogador.getMao()->adicionarCarta(_cartas_para_comer.pop());
        }
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

Jogador *Partida::begin() {
    return &*_jogadores.begin();
}

Jogador *Partida::end() {
    return &*_jogadores.end();
}

void Partida::avancarJogador() {
    _jogador_atual = (unsigned long long)((unsigned long long)((long long) _jogador_atual + (char) _direcao+(long long)_jogadores.size())) % _jogadores.size();
}

void Partida::comerUmaCarta() {
    auto &jogador = _jogadores[_jogador_atual];
    if (_cartas_para_comer.size() == 0) {
        auto ultima_carta = _cartas_na_mesa.pop();
        _cartas_para_comer = _cartas_na_mesa;
        _cartas_para_comer.random();
        _cartas_na_mesa = {ultima_carta};
    }
    auto carta = _cartas_para_comer.pop();
    jogador.getMao()->adicionarCarta(carta);
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
    Jogador *partida_begin(Partida*self) {
        return self->begin();
    }
    Jogador *partida_end(Partida*self) {
        return self->end();
    }
}