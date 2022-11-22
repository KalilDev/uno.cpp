/**
 * @file carta_especial.hpp
 * O arquivo que descreve a classe CartaEspecial e o enum TipoDeCartaEspecial
 */
#pragma once
#include "carta.hpp"

/** foo
 */
enum TipoDeCartaEspecial : numero_da_carta {
    Bloqueia = 10,
    ComeDois = 11,
    Reverso = 12
};

/** foo
 */
class CartaEspecial : public Carta {
private:
    TipoDeCartaEspecial _tipo;
public:
    CartaEspecial(CorDaCarta cor, TipoDeCartaEspecial tipo);
    virtual ~CartaEspecial() override = default;
    TipoDeCartaEspecial getTipo();
};

extern "C" {
    CartaEspecial* cast_carta_to_carta_especial(Carta*);
    TipoDeCartaEspecial carta_especial_get_tipo(CartaEspecial*);
}