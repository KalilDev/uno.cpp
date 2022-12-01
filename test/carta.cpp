/**
 * @file carta.cpp
 * O arquivo que testa a classe Carta
 */
#include "carta.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Metódos de Carta") {
    Carta carta(Azul, 1);

    CHECK(carta.getNumero() == 1);
    CHECK(carta.getCor() == 1 );
    CHECK(carta.toString() == "1 azul");
}

