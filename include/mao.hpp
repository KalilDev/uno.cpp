/**
 * @file mao.hpp
 * @author Bruno Lima Soares (brunolima280103@gmail.com)
 * @brief Classe responsável pela manipulação das cartas de um jogador em uma rodada
 * @version 0.1
 * @date 2022-11-22
 * @details Classe Mão, que implementa métodos para manipular as cartas que estão na
 * "mão" de um jogador em uma rodada, podendo acrescentar novas cartas, remover outras.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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

/**
 * @brief Classe que faz a manipulação das cartas de um usuário em uma rodada
 * 
 * @details Permite o fluxo do jogo e das jogadas, adicionando e removendo cartas 
 * 
 */

class Mao {

private:

    std::vector<Carta *> _cartas;

public:
    
    /**
     * @brief Construtor de um novo objeto mão
     * @details Construtor sem parâmetros para um novo objeto mão
     */
        Mao();

    /**
     * @brief Função que retorna um ponteiro para o início do vector
     * @details Função que pega o ponteiro para o início do vector, desreferencia e faz seu retorno
     * @return Carta* 
     */
        Carta *begin();

    /**
     * @brief Função que retorna um ponteiro para o final do vector
     * @details Função que pega o ponteiro para o fim do vector, desreferencia e faz seu retorno
     * @return Carta* 
     */
        Carta *end();

    /**
     * @brief Função responsável por adicionar uma carta à mão
     * @details Função que recebe uma carta como parâmetro e a insere na última posição do vector que armazena cartas na classe Mão
     * @return * void 
     */
        void adicionarCarta(Carta *);

    /**
     * @brief Função responsável por remover uma carta da mão
     * @details Função que recebe como parâmetro o número de uma carta e remove da mão a carta de número correspondente
     * @return * Carta* 
     */
        Carta *removerCarta(size_t);

    /**
     * @brief Função get que retorna a cor da carta
     * @details Função que retorna a cor de uma carta presente na mão
     * @return CorDaCarta 
     */
        CorDaCarta getCorDaCarta(size_t);

    /**
     * @brief 
     * 
     * @return Carta* 
     */
        Carta *operator[](size_t);
    
        size_t size();

};

extern "C" {
    size_t mao_size(Mao*);
    Carta *mao_begin(Mao*);
    Carta *mao_end(Mao*);
    void mao_adicionar_carta(Mao*, Carta*);
    Carta *mao_remover_carta(Mao*, size_t);
    CorDaCarta mao_get_cor_da_carta(Mao*, size_t);
}