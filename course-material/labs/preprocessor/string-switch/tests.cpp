#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include <string>


int foo(std::string);


#define TEST(n) TEST_CASE("nth_prime(" #n ")") { test(n); }

TEST_CASE("foo(\"a\") == 1")
{
    REQUIRE(foo("a") == 1);
}

TEST_CASE("foo(\"b\") == 1")
{
    REQUIRE(foo("b") == 2);
}

TEST_CASE("foo(\"abc\") == 3")
{
    REQUIRE(foo("abc") == 3);
}

TEST_CASE("foo(\"xyz\") == -1")
{
    REQUIRE(foo("xyz") == -1);
}
