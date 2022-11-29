/**
 * @file jogador.cpp
 * O arquivo que implementa a classe Jogador
 */
#include "jogador.hpp"

Jogador::Jogador(id_jogador id_jogador) {
    _id = id_jogador;
}

Mao* Jogador::getMao(){
    return &_mao;
}

id_jogador Jogador::getId(){
    return _id;
}

extern "C" {
    Mao *jogador_get_mao(Jogador* self){
        return self->getMao();
    }
    id_jogador jogador_get_id(Jogador* self){
        return self->getId();
    }
}