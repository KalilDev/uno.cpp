/**
 * @file capi.h
 * O arquivo que descreve a api em C para o uno
 */
#ifndef CAPI_H
#define CAPI_H


/** carta.hpp
 *
 */
typedef unsigned char numero_da_carta;
enum __attribute__((packed)) CorDaCarta {
    Amarelo = 0,
    Azul = 1,
    Verde = 2,
    Vermelho = 3,
};
struct Carta;
enum CorDaCarta carta_get_cor(struct Carta*);
numero_da_carta carta_get_numero(struct Carta*);
void carta_delete(struct Carta*);

/** carta_especial.hpp
 *
 */
enum __attribute__((packed)) TipoDeCartaEspecial {
    Bloqueia = 10,
    ComeDois = 11,
    Reverso = 12
};
struct CartaEspecial;
struct CartaEspecial* cast_carta_to_carta_especial(struct Carta*);
enum TipoDeCartaEspecial carta_especial_get_tipo(struct CartaEspecial*);
#endif