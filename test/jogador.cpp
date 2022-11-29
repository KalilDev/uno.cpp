/**
 * @file jogador.cpp
 * O arquivo que testa a classe Jogador
 */
#include "jogador.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("id do jogador") {
    Jogador j10(10), j100(100); 
    
    CHECK_EQ(10, j10.getId());
    CHECK_EQ(100, j100.getId());
    
}
TEST_CASE("mao do jogador"){
    auto c = new Carta(CorDaCarta::Vermelho,1);
    auto c1 = new Carta(CorDaCarta::Amarelo,5);
    auto c2 = new Carta(CorDaCarta::Azul,6);

    auto jogador = Jogador{20};
    auto jogador1 = Jogador{30};
    auto jogador2 = Jogador{40};

    jogador.getMao()->adicionarCarta(c);
    jogador1.getMao()->adicionarCarta(c1);
    jogador2.getMao()->adicionarCarta(c2);

    CHECK_EQ(c, jogador.getMao()[0]);
    CHECK_EQ(c1, jogador1.getMao()[0]);
    CHECK_EQ(c2, jogador2.getMao()[0]);

}