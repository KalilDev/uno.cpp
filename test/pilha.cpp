/**
 * @file pilha.cpp
 * O arquivo que testa a classe Pilha
 */
#include "pilha.hpp"
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

TEST_CASE("Construtor e Destrutor") {
    Pilha p; 
    CHECK(p.size() == 0);
    

    auto c = new Carta (CorDaCarta::Amarelo, 2);
    Pilha p1(c);
    CHECK_EQ(*p1.begin(), c);


    bool foi_deletada;
    auto carta_deletada = new CartaQueVaiSerDeletada(&foi_deletada);
    REQUIRE_EQ(false, foi_deletada);
    {
        Pilha p2;
        p2.push(carta_deletada);
    }
    CHECK_EQ(true, foi_deletada);
    
}

TEST_CASE("Size, begin e end"){
    auto c1 = new Carta (CorDaCarta::Verde, 2);
    auto c2 = new Carta (CorDaCarta::Azul, 5);
    auto c3 = new Carta (CorDaCarta::Amarelo, 8);
    Pilha p1;
    p1.push(c1);
    p1.push(c2);
    p1.push(c3);
    CHECK_EQ(p1.size(), 3);
    CHECK_EQ(*p1.begin(), c1);
    CHECK_EQ(p1.end(), p1.begin()+3);
}

TEST_CASE("Pop e getTop"){
    auto c1 = new Carta (CorDaCarta::Verde, 2);
    auto c2 = new Carta (CorDaCarta::Azul, 5);
    auto c3 = new Carta (CorDaCarta::Amarelo, 8);
    Pilha p1;
    p1.push(c1);
    p1.push(c2);
    p1.push(c3);

    auto carta_deletada = p1.getTop();
    CHECK_EQ(carta_deletada, p1.pop());
    CHECK_EQ(p1.size(), 2);
}

TEST_CASE("Random"){
    std::vector<Carta*> cartas;
    Pilha p;

    for (numero_da_carta i = 0; i < 20; i++){
        auto carta = new Carta(CorDaCarta::Vermelho, i);
        cartas.push_back(carta);
        p.push(carta);
    }
    p.random();
    bool isOrdenada = true;

    for (char i = 19; i >= 0; i--){
        auto top_cartas= cartas[static_cast<size_t>(i)];
        auto top_pilha = p.pop();
        if (top_cartas != top_pilha) {
            isOrdenada = false;
            delete top_pilha;
            break;
        }
        delete top_pilha;
    }

    CHECK_EQ(false, isOrdenada);
}

TEST_CASE("Cheia e PopPrimeiraNaoEspecial"){

}

/*
construtor 1 e 2
destrutor 
push
size
getTop
pop
end
begin
random
*/

/*
cheia
popprimeiranaoespecial
pilha
operator=
*/