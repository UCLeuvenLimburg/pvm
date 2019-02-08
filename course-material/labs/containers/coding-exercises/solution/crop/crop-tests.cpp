#include "crop.h"
#include "../Catch.h"


#define ARRAY(...)              __VA_ARGS__
#define TEST(NS, N, EXPECTED)   TEST_CASE("Cropping {" #NS "} by " #N) { std::vector<int> ns { NS }; auto actual = crop(ns, N); std::vector<int> expected {EXPECTED}; REQUIRE(actual == expected); }

TEST(ARRAY(), 1, ARRAY())
TEST(ARRAY(1), 0, ARRAY(1))
TEST(ARRAY(1), 1, ARRAY())
TEST(ARRAY(1, 1), 0, ARRAY(1, 1))
TEST(ARRAY(1, 1), 1, ARRAY())
TEST(ARRAY(1, 1, 1), 1, ARRAY(1))
TEST(ARRAY(1, 2, 3), 0, ARRAY(1, 2, 3))
TEST(ARRAY(1, 2, 3), 1, ARRAY(2))
TEST(ARRAY(1, 2, 3, 4, 5, 6, 7), 1, ARRAY(2, 3, 4, 5, 6))
TEST(ARRAY(1, 2, 3, 4, 5, 6, 7), 2, ARRAY(3, 4, 5))
TEST(ARRAY(1, 2, 3, 4, 5, 6, 7), 3, ARRAY(4))