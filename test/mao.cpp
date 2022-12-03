/**
 * @file mao.cpp
 * O arquivo que testa a classe Mao
 */
#include "mao.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

class CartaQueVaiSerDeletada : public Carta {
private:
    bool* _foi_deletada;
public:
    CartaQueVaiSerDeletada(bool* foi_deletada): Carta::Carta(CorDaCarta::Verde, 100), _foi_deletada(foi_deletada) {
        *foi_deletada = false;
    }
    virtual ~CartaQueVaiSerDeletada() override {
        *_foi_deletada = true;
        Carta::~Carta();
    }
};

TEST_CASE("Tamanho da mao: ") {
    Mao M;
    CHECK_EQ(M.size(), 0);
    M.adicionarCarta(new Carta(CorDaCarta::Vermelho, 2));
    CHECK_EQ(M.size(), 1);
}

TEST_CASE("Teste begin e and: "){
    Mao M;
    auto carta = new Carta(CorDaCarta::Vermelho, 2);
    M.adicionarCarta(carta);
    CHECK_EQ(*M.begin(), M[0]);
    CHECK_EQ(M.end(), M.begin()+1);
}

TEST_CASE("Verificando a função adicionarCarta: "){
    Mao M;
    auto c = new Carta(CorDaCarta::Vermelho, 1);
    M.adicionarCarta(c);
    auto c1 = new Carta(CorDaCarta::Azul, 2);
    M.adicionarCarta(c1);
    CHECK_EQ(c, M[0]);
    CHECK_EQ(c1, M[1]);
}

TEST_CASE("Verificando a função removerCarta: "){
    Mao M;
    auto c = new Carta(CorDaCarta::Vermelho, 1);
    M.adicionarCarta(c);
    auto c1 = new Carta(CorDaCarta::Azul, 2);
    M.adicionarCarta(c1);
    CHECK_EQ(c, M[0]);
    CHECK_EQ(c1, M[1]);
    M.removerCarta(1);
    CHECK_EQ(M[0],c);
    M.removerCarta(0);
    CHECK_EQ(0, M.size());
}

TEST_CASE("destrutor") {
    bool foiDeletada;
    auto carta = new CartaQueVaiSerDeletada(&foiDeletada);
    REQUIRE_EQ(false, foiDeletada);
    {
        auto m = Mao{};
        m.adicionarCarta(carta);
    }
    CHECK_EQ(true, foiDeletada);

}