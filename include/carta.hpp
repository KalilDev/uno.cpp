/**
 * @file carta.hpp
 * @author Gustavo Mota (gstavomota1@gmail.com)
 * @brief Classe responsável por criar as cartas do jogo uno
 * @version 1.0
 * @date 2022-11-30
 * @details O arquivo descreve a classe Carta, o enum CorDaCarta e o tipo numero_da_carta
 * @copyright GNU General Public License v2.0
 *
 */
#pragma once
#include <string>

/**
 * @brief Define um novo "nome" para unsigned char
 * @details Permite na declaração de uma unsigned char usar seu novo
 * "nome" numero_da_carta
 */
typedef unsigned char numero_da_carta;

/** 
 * @brief Cria o enum CorDaCarta que permite associar a cor a um número
 * @details Permite a associação de uma cor de carta a um número, ao adicionar
 * "unsigned char" a definição do enum especifica que a cor só pode ser associada
 * a um byte de memória
 */
enum CorDaCarta : unsigned char {
    Amarelo = 0,
    Azul = 1,
    Verde = 2,
    Vermelho = 3,
};

/** 
 * @brief Cria o modelo de carta do jogo
 * @details A classe Carta funciona como um modelo para a criação 
 * de cartas
 */
class Carta {
private:
    /**
     * @brief Inicializa um enum do tipo unsigned char
     * 
    */
    CorDaCarta _cor;
    /**
     * @brief Inicializa uma váriavel do tipo numero_da_carta (unsigned char)
     * 
    */
    numero_da_carta _numero;

public:
    /**
     * @brief Inicializa o contrutor de Carta
     * @details Contrutor inicializa seus atributos através dos valores
     * recebidos no parâmetro (cor e numero)
    */
    Carta(CorDaCarta cor, numero_da_carta numero);

    /**
     * @brief Adiciona Destrutor de Carta
     * @details O destrutor é invocado quando o objeto saí do escopo
     * da classe, ou quando é deletado o ponteiro que apontava para o 
     * objeto dessa classe. Quando é adicinado um virtual significa que 
     * ao ser chamado o destrutor de Carta, suas classes filhas também podem
     * invocar o destrutor
    */
    virtual ~Carta() = default;

    /**
     * @brief Retorna um unsigned char com a cor da carta
     * @details Função que permite retornar o atributo privado _cor da classe Carta
     * @returns CorDaCarta (unsigned char)
    */
    CorDaCarta getCor() const;

    /**
     * @brief Retorna um unsigned char com o numero da carta
     * @details Função que permite retornar o atributo privado _numero da classe Carta
     * @returns numero_da_carta (unsigned char)
    */
    numero_da_carta getNumero() const;

    /**
     * @brief Função junta o número e a cor da carta em uma string
     * @details A função cria uma váriavel result para concatenar e transformar 
     * _numero e _cor em strings
     * @returns string
    */
    virtual std::string toString() const;
};

extern "C" {
    CorDaCarta carta_get_cor(Carta*);
    numero_da_carta carta_get_numero(Carta*);
    void carta_delete(Carta*);
}