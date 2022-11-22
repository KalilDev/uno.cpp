/**
 * @file pilha.hpp
 * @author Maria Eduarda Sampaio (mariaeduardamrs0@gmail.com)
 * @brief Classe principal com a lógica da pilha
 * @version 0.1
 * @date 2022-11-22
 * @details Responsável por armazenar um vetor de cartas que representa a pilha de lixo :wastebasket: e de comer cartas :yum: :wink:. Possui métodos de retirar a última carta (do topo), embaralhar as cartas e colocar carta no lixo. 
 * @copyright Copyright (c) 2022
 */

#pragma once
#include "carta.hpp"
#include <vector>

class Pilha {
private:
    std::vector<Carta *> _cartas;
public:
/**
 * @brief Construtor de um novo objeto Pilha
 * @details Construtor sem parâmetros para um novo objeto Pilha
 */
    Pilha();

    Pilha(Carta *);

/**
 * @brief Destrutor de um objeto Pilha
 * @details Destrutor de um objeto Pilha
 */
    ~Pilha();

/**
 * @brief Pega a última carta do vetor de cartas
 * @details Pega a última carta do vetor de cartas que representa a carta do topo da pilha de cartas
 * @return Carta* (ponteiro de um objeto Carta)
 */
    Carta *getTop();

/**
 * @brief Retira uma carta do vetor de cartas
 * @details Garante que a carta retirada da pilha teve seu endereço apagado e retorna o endereço da posição inicial do vetor de cartas
 * @return Carta* 
 */
    Carta *pop();

/**
 * @brief Coloca uma carta na pilha de cartas que representa o lixo
 * @param Carta*
 * @details Insere uma nova carta (recebida por parâmetro) à pilha de lixo, que se trata de um vetor de cartas do tipo Carta
 */
    void push(Carta *);

/**
 * @brief Embaralha as cartas
 * @details
 */
    void random();

    static Pilha cheia();

    size_t size();
};