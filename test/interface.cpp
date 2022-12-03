/**
 * @file interface.cpp
 * O arquivo que testa a classe Interface
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "interface.hpp"
#include "doctest.h"

TEST_CASE("Teste da Interface: ") {
    Interface i;
    CHECK_EQ(Interface::const_regras, i.getInstrucoes());
}