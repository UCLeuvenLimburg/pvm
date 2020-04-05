#define CATCH_CONFIG_MAIN
#include "count-bits.h"
#include "catch.h"


TEST_CASE("Count bits of 0b0")
{
    REQUIRE(count_bits(0b0) == 0);
}

TEST_CASE("Count bits of 0b1")
{
    REQUIRE(count_bits(0b1) == 1);
}

TEST_CASE("Count bits of 0b10")
{
    REQUIRE(count_bits(0b10) == 1);
}

TEST_CASE("Count bits of 0b11")
{
    REQUIRE(count_bits(0b11) == 2);
}

TEST_CASE("Count bits of 0b110")
{
    REQUIRE(count_bits(0b110) == 2);
}

TEST_CASE("Count bits of 0b1010")
{
    REQUIRE(count_bits(0b1010) == 2);
}

TEST_CASE("Count bits of 0b11010")
{
    REQUIRE(count_bits(0b11010) == 3);
}

TEST_CASE("Count bits of 0b111010")
{
    REQUIRE(count_bits(0b111010) == 4);
}

TEST_CASE("Count bits of 0b100000000000")
{
    REQUIRE(count_bits(0b100000000000) == 1);
}

TEST_CASE("Count bits of 0b100000000000000000001000")
{
    REQUIRE(count_bits(0b100000000000000000001000) == 2);
}
