/**
* @file util.hpp
* @author Pedro Morato Kalil (pedro-m-kalil@ufmg.br)
* @brief O arquivo que contem utilidades comuns aos outros arquivos
* @version 0.1
* @date 2022-11-22
* @copyright Copyright (c) 2022
*/
#pragma once
#include <exception>

/**
 * @brief Converte uma exception em c++ em uma c_string e armazena ela no buffer c_exception
 * @param c_exception o pointer para onde a exception será armazenada
 * @param exception a exception que foi arremessada
 */
void exception_to_c(char** c_exception, const std::exception& exception);