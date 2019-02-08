#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <functional>


unsigned nth_prime(unsigned);

namespace solution
{
    unsigned nth_prime(unsigned);
}

void test(unsigned n)
{
    unsigned expected = solution::nth_prime(n);
    unsigned actual = nth_prime(n);

    REQUIRE(expected == actual);
}

#define TEST(n) TEST_CASE("nth_prime(" #n ")") { test(n); }

TEST(0)
TEST(1)
TEST(2)
TEST(3)
TEST(4)
TEST(5)
TEST(10)
TEST(50)
TEST(100)