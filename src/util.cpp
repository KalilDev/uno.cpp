#include <exception>
#include <cstring>
#include <cstdlib>

void exception_to_c(char** c_exception, const std::exception& exception) {
    auto str = exception.what();
    auto size = std::strlen(str);
    auto buff = (char*)std::malloc(size + 1);
    std::strcpy(buff, str);
    *c_exception=buff;
}