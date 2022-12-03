#include <cstddef>
#include "pilha.hpp"
#include "carta_especial.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

Pilha::Pilha(){

}

Pilha::Pilha(Carta* carta){
    _cartas.push_back(carta);
}

Pilha::~Pilha(){
    for (auto carta: _cartas)
        delete carta;
}

Carta* Pilha::getTop() noexcept(false) {
    if (_cartas.empty()) {
        throw std::range_error("A Pilha está vazia");
    }
    Carta* ultima = _cartas[_cartas.size() - 1];
    return ultima;
}

Carta* Pilha::pop() noexcept(false) {
    if (_cartas.empty()) {
        throw std::range_error("A Pilha está vazia");
    }
    Carta* ultima = _cartas[_cartas.size() - 1];
    _cartas.pop_back();
    return ultima;
}

void Pilha::push(Carta* carta){
    _cartas.push_back(carta);
}

void Pilha::random(){
    unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle (_cartas.begin(), _cartas.end(), std::default_random_engine(seed));
}

Pilha Pilha::cheia(){
    Pilha pilha;
    for (int c = 0; c < 4; c++){
        CorDaCarta cor = static_cast<CorDaCarta>(c);
        for (numero_da_carta i = 0; i < 10; i++)
            pilha.push(new Carta(cor, i));
        
        pilha.push(new CartaEspecial(cor, TipoDeCartaEspecial::Bloqueia));
        pilha.push(new CartaEspecial(cor, TipoDeCartaEspecial::ComeDois));
        pilha.push(new CartaEspecial(cor, TipoDeCartaEspecial::Reverso));
    }
    return pilha;
}

size_t Pilha::size() const {
 return _cartas.size();
}

Carta *Pilha::popPrimeiraNaoEspecial() {
    for (auto it = _cartas.begin(); it != _cartas.end(); it++) {
        auto carta = *it;
        auto carta_especial = cast_carta_to_carta_especial(carta);
        if (carta_especial != nullptr) {
            continue;
        }
        _cartas.erase(it);
        return carta;
    }
    return nullptr;
}

Carta **Pilha::begin() {
    return &*_cartas.begin();
}

Carta **Pilha::end() {
    return &*_cartas.end();
}

Pilha::Pilha(Pilha &&rvalue) noexcept {
    _cartas.reserve(rvalue._cartas.size());
    for (auto & _carta : rvalue._cartas) {
        _cartas.push_back(_carta);
    }
    rvalue._cartas.clear();
}

Pilha& Pilha::operator=(Pilha &&rvalue)  noexcept {
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

extern "C" {
    size_t pilha_size(Pilha *self) {
        return self->size();
    }
    Carta **pilha_begin(Pilha *self) {
        return &*self->begin();
    }
    Carta **pilha_end(Pilha *self) {
        return &*self->end();
    }
}
