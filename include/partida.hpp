/**
* @file partida.hpp
* @author Pedro Morato Kalil (pedro-m-kalil@ufmg.br)
* @brief O arquivo que descreve a classe Partida e o enum DirecaoDaPartida
* @version 0.1
* @date 2022-11-22
* @details Responsável por lidar com o fluxo principal da partida.
* @copyright Copyright (c) 2022
*/
#pragma once
#include "pilha.hpp"
#include "jogador.hpp"
#include "carta.hpp"
#include <vector>

/**
 * @brief A direção do próximo jogador
 */
enum DirecaoDaPartida : char {
    /**
     * @brief O próximo jogador será à direita
     */
    Normal = 1,
    /**
     * @brief O próximo jogador será à esquerda
     */
    Reversa = -1,
};
/**
 * @brief
 * @param direcao A direcao atual da partida
 * @returns A direcao oposta
 */
DirecaoDaPartida direcaoOposta(DirecaoDaPartida direcao);

/**
 * @brief A excessão arremessada quando o jogador tenta jogar fora da vez dele
 */
class NaoESuaVez : std::exception {
private:
/**
 * @brief O id do jogador que tentou jogar fora da vez
 */
    id_jogador _jogador;
/**
 * @brief A string com o texto dessa exception
 */
    const std::string _string;
public:
    NaoESuaVez(id_jogador);

    virtual const char* what() const noexcept override;
};

/**
 * @brief A excessão arremessada quando o jogador tenta jogar uma carta que não pode ser jogada
 */
class CartaInvalida : std::exception {
private:
/**
 * @brief O id do jogador
 */
    id_jogador _jogador;

/**
 * @brief A ultima carta jogada na pilha
 */
    Carta* _ultima_carta;

/**
 * @brief A carta que o jogador tentou jogar
 */
    Carta* _nova_carta;
/**
 * @brief A string com o texto dessa exception
 */
    const std::string _string;
public:
    CartaInvalida(id_jogador, Carta*, Carta*);
    virtual const char* what() const noexcept override;
};

/**
 * @brief A classe que controla uma partida
 * @details A classe que controla a direção da partida, o jogador que está jogando, os jogadores, a pilha de cartas para comer e a pilha de cartas jogadas
 */
class Partida {
private:

/**
 * @brief A direção atual da partida
 */
    DirecaoDaPartida _direcao = DirecaoDaPartida::Normal;

/**
 * @brief O id do jogador atual
 */
    id_jogador _jogador_atual;

/**
 * @brief A pilha de cartas que já foram jogadas na mesa
 */
    Pilha _cartas_na_mesa;

/**
 * @brief A pilha de cartas que serão comidas
 */
    Pilha _cartas_para_comer;

/**
 * @brief Os jogadores da partida
 */
    std::vector<Jogador> _jogadores;
public:

/**
 * @brief O construtor que cria uma partida vazia
 */
    Partida();

/**
 * @brief A direção atual da partida
 */
    DirecaoDaPartida getDirecao() const;

/**
 * @brief O id do jogador atual
 */
    id_jogador getJogadorAtual() const;

/**
 * @brief Tenta jogar a carta e avançar a partida
 * @param id_jogador o id do jogador
 * @param i o índice da carta
 * @details Verifica se é a vez do jogador, verifica se a carta pode ser jogada, executa as ações necessárias caso a carta seja especial e avança a partida
 */
    void jogarCarta(id_jogador id_jogador, size_t i) noexcept(false);

/**
 * @brief A cor da ultima carta jogada
 */
    CorDaCarta getCorDaPartida() noexcept(false);

/**
 * @brief Tenta comer a carta
 * @param id_jogador o id do jogador
 * @details Verifica se é a vez do jogador, come a carta e avança a partida
 */
    void comerCarta(id_jogador id_jogador);

/**
 * @brief Reinicia o estado
 * @details Limpa as pilhas e cria 4 jogadores com 7 cartas cada
 */
    void iniciarEstado();

/**
 * @brief Limpa o estado
 * @details Remove todos os jogadores e limpa as pilhas
 */
    void limparEstado();

/**
 * @brief Faz o bot jogar uma partida
 */
    void jogarBot();
/**
 * @brief Retorna o id do vencedor da partida ou -1 quando a partida não tem vencedor
 */
    int getVencedor();
/**
 * @brief Retorna a pilha de cartas que já foram jogadas na mesa
 */
    const Pilha *getCartasNaMesa() const;

/**
 * @brief Retorna a pilha de cartas que serão comidas
 */
    const Pilha *getCartasParaComer() const;
/**
 * @brief Retorna o pointer para o jogador no indice i
 * @param i indice
 */
    Jogador *operator[](size_t i);
/**
 * @brief O iterator para o begin() de _jogadores
 */
    Jogador *begin();
/**
 * @brief O iterator para o end() de _jogadores
 */
    Jogador *end();

/**
 * @brief Retorna a quantidade de jogadores
 */
    size_t size() const;

private:

/**
 * @brief Avança o _jogadorAtual
 */
    void avancarJogador();

/**
 * @brief Faz o _jogadorAtual comer uma carta
 */
    void comerUmaCarta();
};

extern "C" {
    DirecaoDaPartida partida_get_direcao(Partida*);
    id_jogador partida_get_jogador_atual(Partida*);
    void partida_jogar_carta(Partida*,id_jogador, size_t, char** e);
    CorDaCarta partida_get_cor_da_partida(Partida*);
    void partida_comer_carta(Partida*,id_jogador, char** e);
    void partida_jogar_bot(Partida*);
    const Pilha *partida_get_cartas_na_mesa(Partida*);
    const Pilha *partida_get_cartas_para_comer(Partida*);
    int partida_get_vencedor(Partida*);
    size_t partida_size(Partida*);
    Jogador *partida_at(Partida*, size_t, char**);
    Jogador *partida_begin(Partida*);
    Jogador *partida_end(Partida*);
}
