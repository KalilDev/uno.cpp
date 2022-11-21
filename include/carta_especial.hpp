/**
 * @file carta_especial.hpp
 * O arquivo que descreve a classe CartaEspecial e o enum TipoDeCartaEspecial
 */
#pragma once
#include "carta.hpp"

/** foo
 */
enum TipoDeCartaEspecial : unsigned char {
    Bloqueia,
    ComeDois,
    Reverso
};

class CartaEspecial : public Carta {
private:
    TipoDeCartaEspecial _tipo;
public:
    CartaEspecial();
    TipoDeCartaEspecial getTipo();
};