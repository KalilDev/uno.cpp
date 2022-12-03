/**
 * @file util.cpp
 * O arquivo que testa o arquivo util
 */
#include "util.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <string>
#include <cstring>

class Exception : public std::exception {
private:
    std::string _message;
public:
    Exception(): _message("Exception") {}
    const char *what() const noexcept {
        return _message.c_str();
    }
};

TEST_CASE("Teste para c string") {
    char *erro;
    exception_to_c(&erro, Exception());
    CHECK_EQ(0, strcmp(erro, "Exception"));
}