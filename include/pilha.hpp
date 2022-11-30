#pragma once
#include "carta.hpp"
#include <vector>

/**
 * @file pilha.hpp
 * @author Maria Eduarda Sampaio (mariaeduardamrs0@gmail.com)
 * @brief Classe principal com a lógica da pilha
 * @version 0.1
 * @date 2022-11-22
 * @details Responsável por armazenar um vetor de cartas que representa a pilha de lixo :wastebasket: e de comer cartas :yum: :wink:. Possui métodos de retirar a última carta (do topo), embaralhar as cartas e colocar carta no lixo. 
 * @copyright Copyright (c) 2022
 */

class Pilha {
private:
/**
 * @brief vetor de cartas que representa a pilha da partida
 */
    std::vector<Carta *> _cartas;
public:
/**
 * @brief Construtor de um novo objeto Pilha
 * @details Construtor sem parâmetros para um novo objeto Pilha, usado no início do jogo 
 */
    Pilha();

/**
 * @brief Construtor de um novo objeto Pilha com parâmetro
 * @details Construtor que recebe o parâmetro do endereço de uma carta para adicioná-la na última posição do vetor de cartas
 */
    Pilha(Carta* carta);

/**
 * @brief Destrutor de um objeto Pilha
 * @details Destrutor de um objeto Pilha para liberar a memória alocada dinâmicamente pela classe 
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
 * @details Retira a última carta do vetor de cartas usando pop_back e retorna a carta retirada
 * @return Carta* (ponteiro de uma carta do tipo objeto Carta)
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
 * @details Embaralha as cartas após o vetor de cartas estiver completamente construido usando shuffle e uma semente aleatória
 */
    void random();
/**
 * @brief Preenche o vetor de cartas no início da partida
 * @details Função do tipo static que preenche o vetor de cartas com todas as cartas do jogo ordenadas com as cores determinadas por um Enum CorDaCarta (determinadas na classe Carta). É inserido no objeto pilha uma carta alocada dinamicamente com sua cor e seu número (0 a 9), além das cartas especiais, que possuem suas cores e seus respectivos tipos (bloqueia, comeDois e reverso)
 * @return Pilha
 */
    static Pilha cheia();
/**
 * @brief retorna o tamanho do vetor de cartas
 * @details retorna o tamanho do vetor de cartas que representa uma pilha da partida
 * @return size_t 
 */
    size_t size();

/**
 * @brief Retira a primeira carta não especial
 * @details Retira e retorna a primeira carta não especial para ser lançada como a primeira carta do começo do jogo
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