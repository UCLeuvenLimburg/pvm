#include "lone-wolf.h"
#include "../Catch.h"


void test(int* ns, int size, int expected)
{
    REQUIRE(lone_wolf(ns, size) == expected);
}

#define ARRAY(...) __VA_ARGS__
#define TEST(expected, array) TEST_CASE("Lone wolf in " #array ", expected = " #expected) { int ns[] = { array }; test(ns, sizeof(ns) / sizeof(int), expected); }


TEST(1, ARRAY(1))
TEST(1, ARRAY(1, 2, 2))
TEST(1, ARRAY(1, 2, 2, 3, 3))
TEST(1, ARRAY(2, 1, 2, 3, 3))
TEST(1, ARRAY(2, 2, 1, 3, 3))
TEST(1, ARRAY(2, 2, 3, 1, 3))
TEST(5, ARRAY(2, 2, 3, 5, 3))
TEST(9, ARRAY(2, 2, 5, 3, 5, 3, 9))
TEST(7, ARRAY(1, 1, 7, 1, 1, 2, 2, 3, 3, 3, 3))
TEST(7, ARRAY(1, 3, 7, 1, 1, 2, 3, 1, 3, 2, 3))
TEST(4, ARRAY(4, 4, 4))
