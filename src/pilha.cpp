#include "pilha.hpp"
#include "carta_especial.hpp"

Pilha::Pilha(){

}

Pilha::Pilha(Carta* carta){

}

Pilha::~Pilha(){
    for (auto carta: _cartas)
        delete carta;
}

Carta* Pilha::getTop(){
    Carta* ultima = _cartas[_cartas.size() - 1];
    return ultima;
}

Carta* Pilha::pop(){
    Carta *ultima = _cartas[_cartas.size() - 1];
    _cartas.pop_back();
    return ultima;
}

void Pilha::push(Carta* carta){
    _cartas.push_back(carta);
}

void Pilha::random(){

}

Pilha Pilha::cheia(){
    Pilha pilha;
    for (int c = 0; c < 4; c++){
        CorDaCarta cor = static_cast<CorDaCarta>(c);
        for (int i = 0; i < 10; i++)
            pilha.push(new Carta(cor, i));
        
        pilha.push(new CartaEspecial(cor, TipoDeCartaEspecial::Bloqueia));
        pilha.push(new CartaEspecial(cor, TipoDeCartaEspecial::ComeDois));
        pilha.push(new CartaEspecial(cor, TipoDeCartaEspecial::Reverso));
    }
}

size_t Pilha::size(){
 return _cartas.size();
}

