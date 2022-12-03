/**
 * @file interface.cpp
 * @author Raissa Diniz (raissagdiniz@gmail.com)
 * @brief Classe responsável pela interface/ menu do jogo
 * @version 1.0
 * @date 2022-11-22
 * @details A classe interface funciona como uma espécie de menu, sendo responsável por disponibilizar
 * diferentes opções de interação do jogador com o jogo,  são elas:
 * começar, reiniciar ou sair do jogo, além da leitura das instruções;
 * @copyright GNU General Public License v2.0
 *
 */
#pragma once
#include "partida.hpp"
#include <string>

/**
 * @brief Disponibiliza um pequeno menu ao usuário.
 *
 * @details Permite ao usuário escolher quando deseja começar, sair, ou reiniciar a partida, além da opção
 * de ler as instruções do jogo.
 */
class Interface
{
private:
    /**
     * @brief inicializa um objeto do tipo Partida.
     *
     */
    Partida _partida;

public:
    /**
     * @brief inicializa um objeto do tipo const char*, de modo a sempre ser possível acessar as regras do jogo.
     *
     */
    static const char* const_regras;
    /**
     * @brief Constrói um objeto do tipo Interface.
     * @details Inicialização sem parâmetros.
     */
    Interface();

    /**
     * @brief Retorna o endereço do objeto Partida criado.
     * @details Função que permite retornar um atributo privado da classe.
     * @returns Partida.
     *
     */
    Partida *getPartida();

    /**
     * @brief Retorna uma string com todas as instruções específicas ao jogo.
     * @details A declaração do tipo const char* resulta no retorno de uma string imutável,
     * @returns const char*;
     *
     */
    const char *getInstrucoes() const;

    /**
     * @brief Fornece ao usuário a opção de parar a partida e não continuar jogando.
     * @details Chama uma função da classe Partida para limpar completamente o estado atual do jogo.
     */
    void sair();

    /**
     * @brief Fornece ao usuário a opção de recomeçar a partida.
     * @details Chama uma função da classe Partida para limpar completamente o 
     * estado atual do jogo e iniciar novamente;
     */
    void resetar();

    /**
     * @brief Permite ao jogador começar a partida.
     * @details Chama uma função da classe Partida para iniciar o estado do jogo.
     *
     */
    void comecar();
};

extern "C"
{
    Interface *interface_new();
    void interface_delete(Interface *);
    Partida *interface_get_partida(Interface *);
    const char *interface_get_instrucoes(Interface *);
    void interface_sair(Interface *);
    void interface_resetar(Interface *);
    void interface_comecar(Interface *);
}