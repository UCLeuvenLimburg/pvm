#include "trim.h"
#include "../Catch.h"


TEST_CASE("Trimming \"\"")
{
    std::string actual = "";
    std::string expected = "";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \"a\"")
{
    std::string actual = "a";
    std::string expected = "a";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \" a\"")
{
    std::string actual = " a";
    std::string expected = "a";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \"  a\"")
{
    std::string actual = "  a";
    std::string expected = "a";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \"a \"")
{
    std::string actual = "a ";
    std::string expected = "a";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \"a  \"")
{
    std::string actual = "a  ";
    std::string expected = "a";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \"a b c\"")
{
    std::string actual = "a b c";
    std::string expected = "a b c";

    trim(&actual);

    REQUIRE(actual == expected);
}

TEST_CASE("Trimming \"      a   b   c   \"")
{
    std::string actual = "      a   b   c   ";
    std::string expected = "a   b   c";

    trim(&actual);

    REQUIRE(actual == expected);
}
