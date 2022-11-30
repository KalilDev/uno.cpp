/**
 * @file carta_especial.cpp
 * O arquivo que testa a classe CartaEspecial
 */
#include "carta_especial.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Metódos de CartaEspecial") {
    CartaEspecial cartaEsp(Amarelo, Bloqueia);

    CHECK(cartaEsp.getCor() == 0);
    CHECK(cartaEsp.getTipo() == 10);
    CHECK(cartaEsp.toString() == "bloqueia amarelo");
}
