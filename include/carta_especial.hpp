/**
 * @file carta_especial.hpp
 * @author Gustavo Mota (gstavomota1@gmail.com)
 * @brief Classe responsável por criar as cartas Especiais do jogo uno
 * @version 1.0
 * @date 2022-11-30
 * @details O arquivo que descreve a classe CartaEspecial e o enum TipoDeCartaEspecial 
 * @copyright GNU General Public License v2.0
 * 
 */
#pragma once
#include "carta.hpp"

/**
 * @brief Cria o enum CorDaCarta que permite associar o tipo ao um número
 * @details Permite a associação de um tipo de carta a um número, ao adicionar
 * "numero_da_carta" (unsigned char) a definição do enum especifica que o tipo só pode
 * ser associado a um byte de memória
 */
enum TipoDeCartaEspecial : numero_da_carta {
    Bloqueia = 10,
    ComeDois = 11,
    Reverso = 12
};

/** 
 * @brief Cria o modelo de carta especial do jogo
 * @details A classe CartaEspecial herda de Carta e define
 * um modelo para a criação de carta especial
 */
class CartaEspecial : public Carta {
private:
    /**
     * @brief Inicializa um enum do tipo numero_da_carta (unsigned char)
    */
    TipoDeCartaEspecial _tipo;

public:
    /**
     * @brief Iniciliza o construtor de CartaEspecial
     * @details Construtor inicializa seu atributo privado tipo e iniciliza 
     * construtor da classe Carte, convertendo o enum de CorDaCarta
     * para TipoDeCartaEspecial
    */
    CartaEspecial(CorDaCarta cor, TipoDeCartaEspecial tipo);

    /**
     * @brief Adiciona Destrutor de CartaEspecial
     * @details O destrutor é invocado quando o objeto saí do escopo
     * da classe, ou quando é deletado o ponteiro que apontava para o 
     * objeto dessa classe. 
    */
    virtual ~CartaEspecial() override = default;

    /**
     * @brief Retorna um numero_da_carta com o tipó da carta especial
     * @details Função que permite retornar o atributo privado _tipo da classe CartaEspecial
     * @returns TipoDeCartaEspecial (unsigned char)
    */
    TipoDeCartaEspecial getTipo();

    /**
     * @brief Função tranforma o _tipo em string
     * @details A função cria uma váriavel result para transformar 
     * o atributo _tipo em string
     * @returns string
    */
    virtual std::string toString() override;
};

extern "C" {
    CartaEspecial* cast_carta_to_carta_especial(Carta*);
    TipoDeCartaEspecial carta_especial_get_tipo(CartaEspecial*);
}