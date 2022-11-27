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
     * @brief Construtor de um objeto mão
     * @details Construtor sem parâmetros para a criação de um novo objeto mão
     */
        Mao();

    /**
     * @brief Função que retorna um ponteiro para o início do vector
     * @details Função que pega o ponteiro para o início do vector, desreferencia e retorna um endereco de memória
     * para a primeira casa do vector
     * @return Carta**
     */
        Carta **begin();

    /**
     * @brief Função que retorna um ponteiro para o final do vector
     * @details Função que pega o ponteiro para o fim do vector, desreferencia e retorna um endereco de memória
     * para a última posição do vector
     * @return Carta**
     */
        Carta **end();

    /**
     * @brief Função responsável por adicionar uma carta à mão
     * @details Função que recebe uma carta como parâmetro por referência e insere essa carta passada como parâmetro
     * na última posição do vector que armazena cartas na classe Mão. A ideia é que esse método seja utilizada quando, 
     * na rodada, o jogador deve acrescentar cartas em sua mão. Nesse caso, a adição da carta ocorrerá por meio da função
     * push_back(), que acrescenta na ultima posição do vector a carta referenciada
     * @return * void 
     */
        void adicionarCarta(Carta * c);

    /**
     * @brief Função responsável por remover uma carta da mão
     * @details Função que recebe como parâmetro o número de uma carta e remove da mão do jogador 
     * a carta de número correspondente no vector. A ideia é que esse método seja utilizado quando,
     * na rodada, o jogador deve remover cartas de sua Mão. A remoção ocorrerá por meio da função
     * erase, apagando o elemento de ("posição inicial do vector" + " i") no vector.
     * @return * Carta* 
     */
        Carta *removerCarta(size_t i);

    /**
     * @brief Função get que retorna a cor da carta
     * @details Função que recebe como parâmetro o número para um índice do vector, em que a função
     * retornará a cor da carta correspondente ao índice passado
     * @return CorDaCarta 
     */
        CorDaCarta getCorDaCarta(size_t i);

    /**
     * @brief Uma sobrescrita do método operator
     * @details Nesse caso, a sobrescrita do operator será responsável por retornar uma referência para
     * o elemento do vector _cartas, na posição i.
     * @return Carta* 
     */
        Carta *operator[](size_t i);
    
    /**
     * @brief Função que retorna o tamanho do vector
     * @details Como estamos utilizando o size_t para padronizar a navegação pelo vector, a ideia deste 
     * método é que retorne o tamanho do vector de cartas, nesse caso, a quantidade de posições que ele
     * possui
     * @return size_t 
     */
        size_t size();

};

extern "C" {
    size_t mao_size(Mao* self);
    Carta **mao_begin(Mao* self);
    Carta **mao_end(Mao* self);
    void mao_adicionar_carta(Mao* self, Carta* c);
    Carta *mao_remover_carta(Mao* self, size_t i);
    Carta *mao_at(Mao* self, size_t i, char**);
    CorDaCarta mao_get_cor_da_carta(Mao* self, size_t i);
}