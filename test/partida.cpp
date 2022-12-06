/**
 * @file partida.cpp
 * O arquivo que testa a classe Partida
 */
#include "partida.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "carta_especial.hpp"

TEST_CASE("partida vazia") {
    auto p = Partida{};
    CHECK_EQ(0, p.size());
    CHECK_EQ(DirecaoDaPartida::Normal, p.getDirecao());
    CHECK_EQ(0, p.getCartasNaMesa()->size());
    CHECK_EQ(0, p.getCartasParaComer()->size());
    CHECK_THROWS(p.getCorDaPartida());
    CHECK_EQ(0, p.getJogadorAtual());
}

TEST_CASE("partida inicial") {
    auto p = Partida{};
    p.iniciarEstado();
    CHECK_EQ(4, p.size());
    CHECK_EQ(DirecaoDaPartida::Normal, p.getDirecao());
    CHECK_EQ(1, p.getCartasNaMesa()->size());
    CHECK_EQ(24 - 1, p.getCartasParaComer()->size());
    auto cor = p.getCartasNaMesa()->getTop()->getCor();
    CHECK_EQ(cor, p.getCorDaPartida());
    CHECK_EQ(0, p.getJogadorAtual());
    for (auto& jogador : p) {
        CHECK_EQ(7, jogador.getMao()->size());
    }
}

TEST_CASE("partida limpa") {
    auto p = Partida{};
    REQUIRE_EQ(0, p.size());
    p.iniciarEstado();
    REQUIRE_EQ(4, p.size());
    p.limparEstado();
    CHECK_EQ(0, p.size());
    CHECK_EQ(DirecaoDaPartida::Normal, p.getDirecao());
    CHECK_EQ(0, p.getCartasNaMesa()->size());
    CHECK_EQ(0, p.getCartasParaComer()->size());
    CHECK_THROWS(p.getCorDaPartida());
    CHECK_EQ(0, p.getJogadorAtual());
}

TEST_CASE("vencedor") {
    auto p = Partida{};
    p.iniciarEstado();
    auto &j = *p[0];
    while (j.getMao()->size() > 0) {
        CHECK_EQ(-1, p.getVencedor());
        delete j.getMao()->removerCarta(0);
    }
    CHECK_EQ(0, p.getVencedor());
}

auto p = [](){
    auto p =Partida{};
    p.iniciarEstado();
    return p;
}();

TEST_CASE("jogar carta") {
    SUBCASE("carta invalida, nao e sua vez e indice invalido") {
        auto &j = *p[0];
        auto cor = p.getCorDaPartida() == CorDaCarta::Verde ? CorDaCarta::Amarelo : CorDaCarta::Verde;
        auto carta = new Carta(cor, p.getCartasNaMesa()->getTop()->getNumero()+1);
        REQUIRE_EQ(7, j.getMao()->size());
        j.getMao()->adicionarCarta(carta);
        CHECK_EQ(8, j.getMao()->size());
        CHECK_THROWS_AS(p.jogarCarta(100, 0), NaoESuaVez);
        CHECK_THROWS_AS(p.jogarCarta(0, 7), CartaInvalida);
        j.getMao()->removerCarta(7);
        CHECK_THROWS_AS(p.jogarCarta(0, 7), std::range_error);
        CHECK_EQ(0, p.getJogadorAtual());
        delete carta;
    }
    SUBCASE("jogar com cor igual") {
        auto &j0 = *p[0];
        auto cor0 = p.getCorDaPartida();
        auto carta0 = new Carta(cor0, p.getCartasNaMesa()->getTop()->getNumero()+1);
        j0.getMao()->adicionarCarta(carta0);
        CHECK_NOTHROW(p.jogarCarta(0, 7));
        CHECK_EQ(1, p.getJogadorAtual());
        auto &j1 = *p[1];
        auto cor1 = p.getCorDaPartida() == CorDaCarta::Verde ? CorDaCarta::Amarelo : CorDaCarta::Verde;
        auto carta1 = new Carta(cor1, p.getCartasNaMesa()->getTop()->getNumero());
        REQUIRE_EQ(7, j1.getMao()->size());
        j1.getMao()->adicionarCarta(carta1);
        CHECK_EQ(8, j1.getMao()->size());
        CHECK_NOTHROW(p.jogarCarta(1, 7));
        CHECK_EQ(2, p.getJogadorAtual());
    }
    SUBCASE("jogar bloqueia") {
        auto &j = *p[2];
        auto cor = p.getCorDaPartida();
        auto carta = new CartaEspecial(cor, TipoDeCartaEspecial::Bloqueia);
        REQUIRE_EQ(7, j.getMao()->size());
        j.getMao()->adicionarCarta(carta);
        CHECK_EQ(8, j.getMao()->size());
        CHECK_NOTHROW(p.jogarCarta(2, 7));
        CHECK_EQ(0, p.getJogadorAtual());

    }
    SUBCASE("jogar reverso") {
        auto &j = *p[0];
        auto cor = p.getCorDaPartida();
        auto carta = new CartaEspecial(cor, TipoDeCartaEspecial::Reverso);
        REQUIRE_EQ(7, j.getMao()->size());
        j.getMao()->adicionarCarta(carta);
        CHECK_EQ(8, j.getMao()->size());
        CHECK_NOTHROW(p.jogarCarta(0, 7));
        CHECK_EQ(3, p.getJogadorAtual());
    }
    SUBCASE("jogar mais dois") {
        auto &j = *p[3];
        auto cor = p.getCorDaPartida();
        auto carta = new CartaEspecial(cor, TipoDeCartaEspecial::ComeDois);
        REQUIRE_EQ(7, j.getMao()->size());
        j.getMao()->adicionarCarta(carta);
        CHECK_EQ(8, j.getMao()->size());
        CHECK_NOTHROW(p.jogarCarta(3, 7));
        CHECK_EQ(9, p[2]->getMao()->size());
        CHECK_EQ(1, p.getJogadorAtual());
    }
}

TEST_CASE("trocar cartas na mesa por cartas para comer") {
    SUBCASE("colocar as cartas na mesa") {
        while (p.getCartasParaComer()->size() > 1) {
            p.getCartasNaMesa()->push(p.getCartasParaComer()->pop());
        }
    }
    SUBCASE("comer a ultima carta") {
        CHECK_EQ(1, p.getCartasParaComer()->size());
        CHECK_NOTHROW(p.comerCarta(p.getJogadorAtual()));
    }
    SUBCASE("checar que as cartas para comer estao cheias e as cartas na mesa contem so a ultima carta") {
        CHECK_EQ(1, p.getCartasNaMesa()->size());
        CHECK_GT(p.getCartasParaComer()->size(), 1);
    }
}

TEST_CASE("tentar comer com o bolo vazio") {
    SUBCASE("limpar o bolo") {
        while(p.getCartasParaComer()->size() > 0) {
            REQUIRE_NOTHROW(p.comerCarta(p.getJogadorAtual()));
        }
    }
    SUBCASE("checar se o jogador nao come carta") {
        auto &j = *p[p.getJogadorAtual()];
        auto len = j.getMao()->size();
        REQUIRE_NOTHROW(p.comerCarta(j.getId()));
        CHECK_EQ(len, j.getMao()->size());
    }
}