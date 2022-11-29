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
/**
 * @brief vetor de cartas que representa a pilha da partida
 */
    std::vector<Carta *> _cartas;
public:
/**
 * @brief Construtor de um novo objeto Pilha
 * @details Construtor sem parâmetros para um novo objeto Pilha
 */
    Pilha();

/**
 * @brief Construtor de um novo objeto Pilha
 * @details Construtor que recebe o parâmetro do endereço de uma carta para adicioná-la na última posição do vetor de cartas
 */
    Pilha(Carta* carta);

/**
 * @brief Destrutor de um objeto Pilha
 * @details Destrutor de um objeto Pilha
 */
    ~Pilha();

    Pilha(Pilha&) = delete;
    Pilha(Pilha&&) noexcept;
    void operator=(Pilha&) = delete;
    Pilha& operator=(Pilha&&) noexcept;

/**
 * @brief Pega a última carta do vetor de cartas
 * @details Pega a última carta do vetor de cartas que representa a carta do topo da pilha de cartas
 * @return Carta* (ponteiro de um objeto Carta)
 */
    Carta *getTop();

/**
 * @brief Retira uma carta do vetor de cartas
 * @details Garante que a carta retirada da pilha teve seu endereço apagado e retorna o endereço da última carta (que foi retirada)
 * @return Carta* 
 */
    Carta *pop();

/**
 * @brief Coloca uma carta na pilha de cartas que representa o lixo
 * @param Carta*
 * @details Insere uma nova carta (recebida por parâmetro) à pilha de lixo, que se trata de um vetor de cartas do tipo Carta
 */
    void push(Carta* carta);

/**
 * @brief Embaralha as cartas
 * @details Embaralha as cartas após o vetor de cartas estiver completamente construido
 */
    void random();
/**
 * @brief Preenche o vetor de cartas no início da partida
 * @details Preenche o vetor de cartas com todas as cartas do jogo ordenadas
 * @return Pilha
 */
    static Pilha cheia();
/**
 * @brief retorna o tamanho do vetor de cartas
 * @details retorna o tamanho do vetor de cartas que representa a pilha da partida
 * @return size_t 
 */
    size_t size();

/**
 * @brief Retorna a primeira carta não especial
 * @details Retorna a primeira carta não especial para o começo do jogo
 * @return Carta*
 */
    Carta* popPrimeiraNaoEspecial();

    Carta** begin();

    Carta** end();
};

extern "C" {
    size_t pilha_size(Pilha*);
    Carta **pilha_begin(Pilha*);
    Carta **pilha_end(Pilha*);
}