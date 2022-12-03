/**
 * @file mao.cpp
 * O arquivo que implementa a classe Mao
 */

#include <stdexcept>
#include <cstring>
#include "mao.hpp"
#include "util.hpp"
    size_t Mao::size() const {
        return _cartas.size();
    }

    Carta **Mao::begin() {
        return &*_cartas.begin();
    }

    Carta **Mao::end(){
        return &*_cartas.end();
    }

    void Mao::adicionarCarta(Carta * c){
        _cartas.push_back(c);
    }

    Carta *Mao::removerCarta(size_t i){
        auto it = _cartas.begin() + (long)i;
        auto carta = *it;
        _cartas.erase(it);
#pragma clang diagnostic push
#pragma ide diagnostic ignored "LocalValueEscapesScope"
        return carta;
#pragma clang diagnostic pop
    }

    CorDaCarta Mao::getCorDaCarta(size_t i) const {
        return _cartas[i]->getCor();
    }

    Carta * Mao::operator[](size_t i) noexcept(false) {
        if(i >= _cartas.size()){
            throw std::range_error("Índice inválido para a mão");
        }
        return _cartas[i];
    }

    Mao::Mao(Mao &&rvalue) noexcept {
        _cartas.reserve(rvalue._cartas.size());
        for(auto & _carta : rvalue._cartas) {
            _cartas.push_back(_carta);
        }
        rvalue._cartas.clear();
    }

    Mao& Mao::operator=(Mao &&rvalue)  noexcept {
        for (auto carta : _cartas) {
            delete carta;
        }
        _cartas.clear();
        _cartas.reserve(rvalue._cartas.size());
        for (auto & _carta : rvalue._cartas) {
            _cartas.push_back(_carta);
        }
        rvalue._cartas.clear();
        return *this;
    }

Mao::~Mao() {
    for (auto carta:_cartas) {
        delete carta;
    }
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