/**
 * @file mao.cpp
 * O arquivo que implementa a classe Mao
 */

#include <stdexcept>
#include <cstring>
#include "mao.hpp"
#include "util.hpp"
    size_t Mao::size(){
        return _cartas.size();
    }

    Carta **Mao::begin(){
        return &*_cartas.begin();
    }

    Carta **Mao::end(){
        return &*_cartas.end();
    }

    void Mao::adicionarCarta(Carta * c){
        _cartas.push_back(c);
    }

    Carta *Mao::removerCarta(size_t i){
        _cartas.erase(_cartas.begin() + (long)i);
    }

    CorDaCarta Mao::getCorDaCarta(size_t i){
        return _cartas[i]->getCor();
    }

    Carta * Mao::operator[](size_t i){
        return _cartas[i];
    }

extern "C" {
    size_t mao_size(Mao* self){
        return self->size();
    }

    Carta **mao_begin(Mao* self){
        return self->begin();
    }

    Carta **mao_end(Mao* self){
        return self->end();
    }

    void mao_adicionar_carta(Mao* self, Carta* c){
        return self->adicionarCarta(c);
    }

    Carta *mao_remover_carta(Mao* self, size_t i){
        return self->removerCarta(i);
    }

    CorDaCarta mao_get_cor_da_carta(Mao* self, size_t i){
        return self->getCorDaCarta(i);
    }
    Carta *mao_at(Mao* self, size_t i, char** e) {
        try {
            *e = nullptr;
            return (*self)[i];
        } catch (const std::range_error& exception) {
            exception_to_c(e, exception);
            return nullptr;
        }
    }
}