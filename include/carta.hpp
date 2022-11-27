/**
 * @file carta.hpp
 * O arquivo que descreve a classe Carta, o enum CorDaCarta e o tipo numero_da_carta
 */
#pragma once
#include <string>

/** foo
 */
typedef unsigned char numero_da_carta;

/** foo
 */
enum CorDaCarta : unsigned char {
    Amarelo = 0,
    Azul = 1,
    Verde = 2,
    Vermelho = 3,
};

/** foo
 */
class Carta {
private:
    CorDaCarta _cor;
    numero_da_carta _numero;
public:
    Carta(CorDaCarta cor, numero_da_carta numero);
    virtual ~Carta() = default;
    CorDaCarta getCor();
    numero_da_carta getNumero();
    virtual std::string toString();
};

extern "C" {
    CorDaCarta carta_get_cor(Carta*);
    numero_da_carta carta_get_numero(Carta*);
    void carta_delete(Carta*);
}