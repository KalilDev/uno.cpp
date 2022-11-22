/**
 * @file capi.h
 * O arquivo que descreve a api em C para o uno
 */
#ifndef CAPI_H
#define CAPI_H
#include <stdlib.h>

/** carta.hpp
 *
 */
typedef unsigned char numero_da_carta;
enum CorDaCarta {
    Amarelo = 0,
    Azul = 1,
    Verde = 2,
    Vermelho = 3,
} __attribute__((packed));
struct Carta;
enum CorDaCarta carta_get_cor(struct Carta*);
numero_da_carta carta_get_numero(struct Carta*);
void carta_delete(struct Carta*);

/** carta_especial.hpp
 *
 */
enum TipoDeCartaEspecial {
    Bloqueia = 10,
    ComeDois = 11,
    Reverso = 12
} __attribute__((packed));
struct CartaEspecial;
struct CartaEspecial* cast_carta_to_carta_especial(struct Carta*);
enum TipoDeCartaEspecial carta_especial_get_tipo(struct CartaEspecial*);

/** map.hpp
 *
 */
struct Mao;
size_t mao_size(struct Mao*);
struct Carta *mao_begin(struct Mao*);
struct Carta *mao_end(struct Mao*);
void mao_adicionar_carta(struct Mao*, struct Carta*);
struct Carta *mao_remover_carta(struct Mao*, size_t);
enum CorDaCarta mao_get_cor_da_carta(struct Mao*, size_t);

/** jogador.hpp
 *
 */
typedef size_t id_jogador;
struct Jogador;

struct Mao *jogador_get_mao(struct Jogador*);
id_jogador jogador_get_id(struct Jogador*);

/** partida.hpp
 *
 */
enum DirecaoDaPartida {
    Normal = 1,
    Reversa = -1,
} __attribute__((packed));
struct Partida;

DirecaoDaPartida partida_get_direcao(struct Partida*);
id_jogador partida_get_jogador_atual(struct Partida*);
void partida_jogar_carta(struct Partida*,id_jogador, size_t);
CorDaCarta partida_get_cor_da_partida(struct Partida*);
void partida_comer_carta(struct Partida*,id_jogador);
void partida_imprime_partida(struct Partida*);
struct Jogador *partida_begin(struct Partida*);
struct Jogador *partida_end(struct Partida*);

/** interface.hpp
 *
 */
struct Interface;
struct Interface* interface_new();
void interface_delete(struct Interface*);
struct Partida *interface_get_partida(struct Interface*);
char *interface_get_instrucoes(struct Interface*);
void interface_sair(struct Interface*);
void interface_resetar(struct Interface*);
void interface_comecar(struct Interface*);

#endif