/**
 * @file carta_especial.cpp
 * O arquivo que implementa a classe CartaEspecial
 */
#include "carta_especial.hpp"

CartaEspecial::CartaEspecial(CorDaCarta cor, TipoDeCartaEspecial tipo) : Carta::Carta(cor,static_cast<numero_da_carta>(tipo)) {
	_tipo = tipo;
}

TipoDeCartaEspecial CartaEspecial::getTipo() {
	return _tipo;
}
std::string CartaEspecial::toString() {
    auto result = std::string{};
    switch (_tipo) {
        case Bloqueia:
            result += "bloqueia";
            break;
        case ComeDois:
            result += "come dois";
            break;
        case Reverso:
            result += "reverso";
            break;
    }
    result += " ";
    switch (getCor()) {
        case Amarelo:
            result += "amarelo";
            break;
        case Azul:
            result += "azul";
            break;
        case Verde:
            result += "verde";
            break;
        case Vermelho:
            result += "vermelho";
            break;
    }
    return result;
}
extern "C" {
CartaEspecial *cast_carta_to_carta_especial(Carta *self) {
    return dynamic_cast<CartaEspecial *>(self);
}
TipoDeCartaEspecial carta_especial_get_tipo(CartaEspecial *self) {
    return self->getTipo();
}
}