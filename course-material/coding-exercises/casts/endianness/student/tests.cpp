#define CATCH_CONFIG_MAIN
#include "endianness.h"
#include "catch.h"


TEST_CASE("is_little_endian")
{
    CHECK(is_little_endian());
}

TEST_CASE("is_big_endian")
{
    CHECK_FALSE(is_big_endian());
}