/**
 * @file partida.hpp
 * O arquivo que descreve a classe Partida e o enum DirecaoDaPartida
 */
#pragma once
#include "pilha.hpp"
#include "jogador.hpp"
#include "carta.hpp"
#include <vector>

/** foo
 */
enum DirecaoDaPartida : char {
    Normal = 1,
    Reversa = -1,
};
DirecaoDaPartida direcaoOposta(DirecaoDaPartida);

class NaoESuaVez : std::exception {
private:
    id_jogador _jogador;
public:
    NaoESuaVez(id_jogador);
};

class CartaInvalida : std::exception {
private:
    id_jogador _jogador;
    Carta*_ultima_carta;
    Carta*_nova_carta;
public:
    CartaInvalida(id_jogador, Carta*, Carta*);
};

/** foo
 */
class Partida {
private:
    DirecaoDaPartida _direcao;
    id_jogador _jogador_atual;
    Pilha _cartas_na_mesa;
    Pilha _cartas_para_comer;
    std::vector<Jogador> _jogadores;
public:
    Partida();
    DirecaoDaPartida getDirecao();
    id_jogador getJogadorAtual();
    void jogarCarta(id_jogador, size_t);
    CorDaCarta getCorDaPartida();
    void comerCarta(id_jogador);
    void iniciarEstado();
    void limparEstado();
    Jogador *begin();
    Jogador *end();
private:
    void avancarJogador();
    void comerUmaCarta();
};

extern "C" {
    DirecaoDaPartida partida_get_direcao(Partida*);
    id_jogador partida_get_jogador_atual(Partida*);
    void partida_jogar_carta(Partida*,id_jogador, size_t);
    CorDaCarta partida_get_cor_da_partida(Partida*);
    void partida_comer_carta(Partida*,id_jogador);
    void partida_imprime_partida(Partida*);
    Jogador *partida_begin(Partida*);
    Jogador *partida_end(Partida*);
}
