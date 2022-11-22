/**
 * @file interface.cpp
 * O arquivo que implementa a classe Interface
 */

#include "interface.hpp"

Interface::Interface();

Partida *Interface::getPartida();

std::string Interface::getInstrucoes()
{
    std::string regras = "Regras do nosso (humilde) Uno:
        1) O jogo consiste em 4 jogadores, com 7 cardas cada;
        2) Além das clássicas cartas numéricas(0 - 9) de cores variadas(amarelo, azul, vermelho e verde), 
        essa versão apresenta três tipos de carta especial(em detrimento às cinco do jogo padrão): 
        - Reverso : muda o sentindo da partida, podendo ser horário ou anti-horário;
        -Bloqueio : impede o jogador seguinte ao que lançou a carta de participar nessa partida;
        - “Come 2” : faz com que o próximo àquele que jogou adicione mais 2 cartas à sua mão.É importante ressaltar que, nesse jogo, essas cartas não são acumulativas, ou seja,
            um outro “come 2” não pode ser jogado em cima de um previamente lançado de modo a “formar um come 4”;
        3) O jogador não possui a possibilidade de gritar “Uno” enquanto joga sua penúltima carta
           (uma vez que isso implicaria na necessidade da criação de um sistema de denúncia para quando isso não acontece);
        4) A interface em que o jogo ocorrerá será o próprio terminal, de mode que, na vez do jogador, 
           será mostrada a lista de cartas em sua mão, e quais suas opções de ação(como “comer”, desistir, jogador determinada carta, etc);
        5) O jogo não possui bots. Dessa maneira, todas as opções discutidas no tópico anterior serão apresentadas no mesmo 
           terminal e consecutivamente, isto é, logo após um jogador ter feito sua jogada, a vez será dada ao próximo."

        return regras;
}

void Interface::sair();

void Interface::resetar();

void Interface::comecar();

extern "C"
{
    Interface *interface_new();

    void interface_delete(Interface *self)
    {
        self->interface_delete;
    }

    Partida *interface_get_partida(Interface *self)
    {
        return self->interface_get_partida;
    }

    char *interface_get_instrucoes(Interface *self)
    {
        return self->interface_get_instrucoes;
    }

    void interface_sair(Interface *self)
    {
        self->interface_sair;
    }

    void interface_resetar(Interface *self)
    {
        self->interface_resatar;
    }

    void interface_comecar(Interface *self)
    {
        self->interface_comecar;
    }
}
