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

