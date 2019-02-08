#include "length.h"
#include "../Catch.h"


TEST_CASE("Length of {}")
{
    int expected = 0;

    REQUIRE(length(nullptr, nullptr) == expected);
}

TEST_CASE("Length of {1}")
{
    int ns[] = { 1 };
    int expected = sizeof(ns) / sizeof(int);

    REQUIRE(length(ns, ns + expected) == expected);
}

TEST_CASE("Length of {1, 2}")
{
    int ns[] = { 1, 2 };
    int expected = sizeof(ns) / sizeof(int);

    REQUIRE(length(ns, ns + expected) == expected);
}

TEST_CASE("Length of {1, 2, 3}")
{
    int ns[] = { 1, 2, 3 };
    int expected = sizeof(ns) / sizeof(int);

    REQUIRE(length(ns, ns + expected) == expected);
}

TEST_CASE("Length of {1, 1, 1, 1, 1}")
{
    int ns[] = { 1, 1, 1, 1, 1 };
    int expected = sizeof(ns) / sizeof(int);

    REQUIRE(length(ns, ns + expected) == expected);
}

TEST_CASE("Length of {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}")
{
    int ns[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int expected = sizeof(ns) / sizeof(int);

    REQUIRE(length(ns, ns + expected) == expected);
}
