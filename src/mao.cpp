/**
 * @file mao.cpp
 * O arquivo que implementa a classe Mao
 */

#include "mao.hpp"

    size_t size(){
        return sizeof(size_t);
    }

    Carta Mao::*begin(){
        return &*_cartas.begin();
    }

    Carta Mao::*end(){
        return &*_cartas.end();
    }

    void Mao::adicionarCarta(Carta * c){
        _cartas.push_back(c);
    }

    Carta Mao::*removerCarta(size_t){
        for(auto &x : _cartas){
            int aux = _cartas.getNumero();
            if(aux == size_t){
                _cartas.erase(x).at(aux);
            }
        }
    }

    CorDaCarta Mao::getCorDaCarta(size_t){
        return _cartas.getCor().at(size_t);
    }

    Carta Mao::*operator[](size_t){

    }

extern "C" {
    size_t mao_size(Mao* self){
        self->mao_size;
    }

    Carta *mao_begin(Mao* self){
        self->mao_begin;
    }

    Carta *mao_end(Mao* self){
        self->mao_end;
    }

    void mao_adicionar_carta(Mao*, Carta*){

    }

    Carta *mao_remover_carta(Mao* self, size_t){
        self->mao_remover_carta;
    }

    CorDaCarta mao_get_cor_da_carta(Mao* self, size_t){
        self->mao_get_cor_da_carta;
    }
}