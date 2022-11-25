/**
 * @file interface.cpp
 * O arquivo que implementa a classe Interface
 */
#include "partida.hpp"
#include "interface.hpp"

const std::char* Interface::const_regras = "1) O jogo consiste em 4 jogadores, com 7 cartas cada;
                          2) As cartas numéricas variam entre 0 e 9, nas cores amarelo, azul, vermelho e verde);
                          3) Nessa versão, existem apenas três tipos de carta especial : 
                                Reverso(muda o sentindo da partida, podendo ser horário ou anti - horário), 
                                Bloqueio(impede o jogador seguinte ao que lançou a carta de participar nessa rodada), 
                                e “Come 2”(faz com que o próximo àquele que jogou adicione mais 2 cartas à sua mão. 
                                Essas cartas não são acumulativas, ou seja, um outro “come 2” não pode ser jogado em cima de um previamente lançado de modo 
                                a “formar um come 4”);
                          4) O jogador não possui a possibilidade de falar “Uno” enquanto joga sua penúltima carta;
                          5) O jogo não possui bots. Dessa maneira, todas as opções disponíveis para realizar a jogada serão 
                          apresentadas na mesma interface e consecutivamente, isto é, logo após um jogador ter feito sua jogada, a vez será dada ao próximo."

Interface::Interface() {
    _partida.resetarEstado();
}

Partida *Interface::getPartida()
{
    return partida;
}

char *Interface::getInstrucoes()
{
    return const_regras;
}

void Interface::sair()
{
}

void Interface::resetar()
{
    _partida.resetarEstado();
}

void Interface::comecar()
{
    _partida.iniciarEstado();
}

extern "C"
{
    Interface *interface_new() |{
        return new Interface();
    }

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
