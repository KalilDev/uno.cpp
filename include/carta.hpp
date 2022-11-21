/**
 * @file carta.hpp
 * O arquivo que descreve a classe Carta, o enum CorDaCarta e o tipo numero_da_carta
 */
#pragma once

/** foo
 */
typedef unsigned char numero_da_carta;

/** foo
 */
enum CorDaCarta : unsigned char {
    Amarelo,
    Azul,
    Verde,
    Vermelho,
};

/** foo
 */
class Carta {
private:
    CorDaCarta _cor;
    numero_da_carta _numero;
public:
    Carta();
    CorDaCarta getCor();
    numero_da_carta getNumero();
};