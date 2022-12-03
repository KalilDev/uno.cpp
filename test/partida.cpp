/**
 * @file partida.cpp
 * O arquivo que testa a classe Partida
 */
#include "partida.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("partida vazia") {
    Partida p;
    CHECK_EQ(0, p.size());
    CHECK_EQ(DirecaoDaPartida::Normal, p.getDirecao());
    CHECK_EQ(0, p.getCartasNaMesa()->size());
    CHECK_EQ(0, p.getCartasParaComer()->size());
    CHECK_THROWS(p.getCorDaPartida());
    CHECK_EQ(0, p.getJogadorAtual());
}