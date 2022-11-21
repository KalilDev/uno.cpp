/**
 * @file mao.hpp
 * O arquivo que descreve a classe Mao
 */
#pragma once
#include <cstdlib>
#include <vector>
#include "carta.hpp"

/** foo
 */
class Mao {
private:
    std::vector<Carta *> _cartas;
public:
    Mao();
    const std::vector<Carta *> *getCartas();
    void adicionarCarta(Carta *);
    Carta *removerCarta(size_t);
    CorDaCarta getCorDaCarta(size_t);
};