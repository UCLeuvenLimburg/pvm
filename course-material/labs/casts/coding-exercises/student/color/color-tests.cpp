#include "color.h"
#include "../Catch.h"


TEST_CASE("Casting (0, 0, 0, 0)")
{
    ARGB argb;
    argb.a = 0;
    argb.r = 0;
    argb.g = 0;
    argb.b = 0;

    REQUIRE(convert_to_uint(argb) == 0x00000000);
}

TEST_CASE("Casting (255, 0, 0, 0)")
{
    ARGB argb;
    argb.a = 255;
    argb.r = 0;
    argb.g = 0;
    argb.b = 0;

    REQUIRE(convert_to_uint(argb) == 0xFF000000);
}

TEST_CASE("Casting (0, 255, 0, 0)")
{
    ARGB argb;
    argb.a = 0;
    argb.r = 255;
    argb.g = 0;
    argb.b = 0;

    REQUIRE(convert_to_uint(argb) == 0x00FF0000);
}

TEST_CASE("Casting (0, 0, 255, 0)")
{
    ARGB argb;
    argb.a = 0;
    argb.r = 0;
    argb.g = 255;
    argb.b = 0;

    REQUIRE(convert_to_uint(argb) == 0x0000FF00);
}

TEST_CASE("Casting (0, 0, 0, 255)")
{
    ARGB argb;
    argb.a = 0;
    argb.r = 0;
    argb.g = 0;
    argb.b = 255;

    REQUIRE(convert_to_uint(argb) == 0x000000FF);
}
