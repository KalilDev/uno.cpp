/**
 * @file interface.cpp
 * O arquivo que implementa a classe Interface
 */
#include "partida.hpp"
#include "interface.hpp"

const char* Interface::const_regras = "1) O jogo consiste em 4 jogadores, com 7 cartas cada;\n"
                                      "2) As cartas numéricas variam entre 0 e 9, nas cores amarelo, azul, vermelho e verde);\n"
                                      "3) Nessa versão, existem apenas três tipos de carta especial :\n"
                                      "   Reverso(muda o sentindo da partida, podendo ser horário ou anti - horário),\n"
                                      "   Bloqueio(impede o jogador seguinte ao que lançou a carta de participar nessa rodada),\n"
                                      " e Come 2”(faz com que o próximo àquele que jogou adicione mais 2 cartas à sua mão.\n"
                                      "   Essas cartas não são acumulativas, ou seja, um outro “come 2” não pode ser jogado em cima de um previamente lançado de modo\n"
                                      "   a “formar um come 4”);\n"
                                      "4) O jogador não possui a possibilidade de falar “Uno” enquanto joga sua penúltima carta;\n"
                                      "5) O jogo não possui bots. Dessa maneira, todas as opções disponíveis para realizar a jogada serão\n"
                                      "   apresentadas na mesma interface e consecutivamente, isto é, logo após um jogador ter feito sua jogada, a vez será dada ao próximo.";

Interface::Interface() {
    _partida.iniciarEstado();
}

Partida *Interface::getPartida()
{
    return &_partida;
}

const char *Interface::getInstrucoes()
{
    return Interface::const_regras;
}

void Interface::sair()
{
    _partida.limparEstado();
}

void Interface::resetar()
{
    _partida.limparEstado();
    _partida.iniciarEstado();
}

void Interface::comecar()
{
    _partida.iniciarEstado();
}

extern "C"
{
    Interface *interface_new() {
        return new Interface();
    }

    void interface_delete(Interface *self)
    {
        delete self;
    }

    Partida *interface_get_partida(Interface *self)
    {
        return self->getPartida();
    }

    const char *interface_get_instrucoes(Interface *self)
    {
        return self->getInstrucoes();
    }

    void interface_sair(Interface *self)
    {
        self->sair();
    }

    void interface_resetar(Interface *self)
    {
        self->resetar();
    }

    void interface_comecar(Interface *self)
    {
        self->comecar();
    }
}
