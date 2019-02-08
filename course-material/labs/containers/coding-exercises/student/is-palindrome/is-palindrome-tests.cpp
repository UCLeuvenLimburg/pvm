#include "is-palindrome.h"
#include "../Catch.h"

#define ARRAY(...)              __VA_ARGS__
#define TEST(expected, elts)    TEST_CASE("Is {" #elts "} a palindrome?") { std::vector<int> vec { elts }; REQUIRE(expected == is_palindrome(vec)); }

TEST(true, ARRAY())
TEST(true, ARRAY(1))
TEST(true, ARRAY(1, 1))
TEST(true, ARRAY(1, 1, 1))
TEST(true, ARRAY(1, 2, 1))
TEST(true, ARRAY(1, 2, 2, 1))
TEST(true, ARRAY(1, 2, 3, 2, 1))
TEST(true, ARRAY(1, 2, 3, 4, 3, 2, 1))
TEST(false, ARRAY(1, 2))
TEST(false, ARRAY(1, 2, 2))
TEST(false, ARRAY(1, 2, 2, 1, 3))
TEST(true, ARRAY(3, 1, 2, 5, 2, 1, 3))
