/**
 * @file interface.hpp
 * O arquivo que descreve a classe Interface
 */
#pragma once
#include "partida.hpp"
#include <string>

/** foo
 */
class Interface {
private:
    Partida _partida;
public:
    Interface();
    Partida *getPartida();
    std::string getInstrucoes();
    void sair();
    void resetar();
    void comecar();
};

extern "C" {
    Interface* interface_new();
    void interface_delete(Interface*);
    Partida *interface_get_partida(Interface*);
    char *interface_get_instrucoes(Interface*);
    void interface_sair(Interface*);
    void interface_resetar(Interface*);
    void interface_comecar(Interface*);
}