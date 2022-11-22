/**
 * @file interface.cpp
 * @author Raissa Diniz (raissagdiniz@gmail.com)
 * @brief Classe responsável pela interface/ menu do jogo
 * @version 1.0
 * @date 2022-11-22
 * @details A classe interface funciona como uma espécie de menu, sendo responsável por disponibilizar
 * diferentes opções de interação do jogador com o jogo através do terminal, são elas:
 * começar, reiniciar ou sair do jogo, e ler as instruções;
 *
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
     * @brief Constrói um objeto do tipo Interface.
     *
     * @details Inicialização sem parâmetros.
     */
    Interface();

    /**
     * @brief Retorna um ponteiro para um objeto do tipo Partida.
     *
     */
    Partida *getPartida();

    /**
     * @brief Retorna uma string com todas as instruções específicas ao jogo.
     *
     */
    std::string getInstrucoes();

    /**
     * @brief Fornece ao usuário a opção de desistir da partida e não continuar jogando.
     *
     */
    void sair();

    /**
     * @brief Fornece ao usuário a opção de recomeçar a partida.
     */
    void resetar();

    /**
     * @brief Permite ao jogador começar a partida.
     *
     */
    void comecar();
};

extern "C"
{
    Interface *interface_new();
    void interface_delete(Interface *);
    Partida *interface_get_partida(Interface *);
    char *interface_get_instrucoes(Interface *);
    void interface_sair(Interface *);
    void interface_resetar(Interface *);
    void interface_comecar(Interface *);
}