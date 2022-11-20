#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "add.hpp"
#include "doctest.h"

TEST_CASE("add") {
    CHECK_EQ(2,add(1,1));
    CHECK_EQ(200,add(100,100));
}

