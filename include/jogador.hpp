/**
 * @file jogador.hpp
 * @author Raphael Lucas Silva Amaral (raphaelamaral1069@hotmail.com)
 * @brief Classe principal com a lógica do Jogador
 * @version 0.1
 * @date 2022-11-26
 * @details Responsável por criar um jogador novo, mostrar sua mão de cartas e seu id (identificador).
 * @copyright Copyright (c) 2022
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
/**
 * @brief Cada jogador possui uma mão e um identificador
 */
    Mao _mao;
    id_jogador _id;
public:
/**
 * @brief Construtor de um novo objeto Jogador
 * @details Construtor que recebe o parâmetro do identificador do jogador
 */
    Jogador(id_jogador);

/**
 * @brief Pega a mão do jogador
 * @details Função que mostra qual é a mão do jogador no momento
 * @return Mao* (ponteiro de uma mão)
 */
    Mao *getMao();

/**
 * @brief Pega o identificador do jogador
 * @details Função que retorna qual o identificador do jogador em questão
 * @return id_jogador 
 */
    id_jogador getId();
};

/**
 * @brief Esquema que faz referência a linguagem C
 * @details Serve para que haja a conexão com a linguagem dart
 */
extern "C" {
    Mao *jogador_get_mao(Jogador*);
    id_jogador jogador_get_id(Jogador*);
}