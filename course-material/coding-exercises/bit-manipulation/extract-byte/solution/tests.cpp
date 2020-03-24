#define CATCH_CONFIG_MAIN
#include "extract-byte.h"
#include "catch.h"


TEST_CASE("Extract byte 0 from 0x00")
{
    REQUIRE(extract_byte(0x00, 0) == 0x00);
}

TEST_CASE("Extract byte 0 from 0x01")
{
    REQUIRE(extract_byte(0x01, 0) == 0x01);
}

TEST_CASE("Extract byte 0 from 0x0100")
{
    REQUIRE(extract_byte(0x0100, 0) == 0x00);
}

TEST_CASE("Extract byte 1 from 0x0100")
{
    REQUIRE(extract_byte(0x0100, 1) == 0x01);
}

TEST_CASE("Extract byte 0 from 0x1234")
{
    REQUIRE(extract_byte(0x1234, 0) == 0x34);
}

TEST_CASE("Extract byte 1 from 0x1234")
{
    REQUIRE(extract_byte(0x1234, 1) == 0x12);
}

TEST_CASE("Extract byte 0 from 0x76543210")
{
    REQUIRE(extract_byte(0x76543210, 0) == 0x10);
}

TEST_CASE("Extract byte 1 from 0x76543210")
{
    REQUIRE(extract_byte(0x76543210, 1) == 0x32);
}

TEST_CASE("Extract byte 2 from 0x76543210")
{
    REQUIRE(extract_byte(0x76543210, 2) == 0x54);
}

TEST_CASE("Extract byte 3 from 0x76543210")
{
    REQUIRE(extract_byte(0x76543210, 3) == 0x76);
}
