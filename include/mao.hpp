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
    size_t size();
    Carta *begin();
    Carta *end();
    void adicionarCarta(Carta *);
    Carta *removerCarta(size_t);
    CorDaCarta getCorDaCarta(size_t);
};

extern "C" {
    size_t mao_size(Mao*);
    Carta *mao_begin(Mao*);
    Carta *mao_end(Mao*);
    void mao_adicionar_carta(Mao*, Carta*);
    Carta *mao_remover_carta(Mao*, size_t);
    CorDaCarta mao_get_cor_da_carta(Mao*, size_t);
}