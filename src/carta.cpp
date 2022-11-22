/**
 * @file carta.cpp
 * O arquivo que implementa a classe Carta
 */
#include "carta.hpp"

Carta::Carta(CorDaCarta cor, numero_da_carta numero) {
	_cor = cor;
	_numero = numero;
}

CorDaCarta Carta::getCor() {
	return _cor;
}

numero_da_carta Carta::getNumero(){
	return _numero;
}

extern "C" {
	CorDaCarta carta_get_cor(Carta* self) {
		return self->getCor();
	};
	numero_da_carta carta_get_numero(Carta* self) {
		return self->getNumero();
	};
	void carta_delete(Carta* self) {
		return self->~Carta();
	};
}

