/**
 * @file mao.cpp
 * O arquivo que testa a classe Mao
 */
#include "mao.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Tamanho da mao: ") {
    Mao M;
    CHECK(M.size() == 0);
    M.adicionarCarta(new Carta(CorDaCarta::Vernelho, 2));
    CHECK(M.size() == 1);
}
