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

