/**
 * @file jogador.hpp
 * O arquivo que descreve a classe Jogador e o tipo id_jogador
 */
#pragma once
#include <cstdlib>
#include "mao.hpp"

/** foo
 */
typedef size_t id_jogador;

/** foo
 */
class Jogador {
private:
    Mao _mao;
    id_jogador _id;
public:
    Jogador();
    Mao *getMao();
    id_jogador getId();
};