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
    void imprimePartida();
private:
    void avancarJogador();
};
