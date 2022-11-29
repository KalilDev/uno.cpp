#include "pilha.hpp"
#include "carta_especial.hpp"
#include <algorithm>
#include <random>
#include <chrono>

Pilha::Pilha(){

}

Pilha::Pilha(Carta* carta){
    _cartas.push_back(carta);
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
    Carta* ultima = _cartas[_cartas.size() - 1];
    _cartas.pop_back();
    return ultima;
}

void Pilha::push(Carta* carta){
    _cartas.push_back(carta);
}

void Pilha::random(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (_cartas.begin(), _cartas.end(), std::default_random_engine(seed));
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

Carta* Pilha::popPrimeiraNaoEspecial(){
    for (auto it = _cartas.begin(); it != _cartas.end(); it++){
        auto carta = *it;
        CartaEspecial *carta_especial = (CartaEspecial*) carta;
        if (carta_especial != nullptr) { //conseguiu converter então é para ignorar
            continue; // passa para a próxima carta/proxima iteração
        } 
        else {
            _cartas.erase(it); //se n for especial dá o erase
            return carta; //retorna a carta n especial 
            break; // faz o pop da primeira não especial e sai do for
        }
    }
}