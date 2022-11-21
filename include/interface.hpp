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
    std::string getInstrucoes();
    void sair();
    void resetar();
    void comecar();
};