/**
 * @file pilha.hpp
 * O arquivo que descreve a classe Pilha
 */
#pragma once
#include "carta.hpp"
#include <vector>

/** foo
 */
class Pilha {
private:
    std::vector<Carta *> _cartas;
public:
    Pilha();
    Carta *getTop();
    Carta *pop();
    void push(Carta *);
    void random();
};