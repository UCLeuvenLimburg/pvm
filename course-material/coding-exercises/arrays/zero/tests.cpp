#define CATCH_CONFIG_MAIN
#include "solution.h"
#include "catch.h"


TEST_CASE("Zeroing {}")
{
    zero(nullptr, 0);
}

TEST_CASE("Zeroing { 1 }")
{
    int ns[] = { 1 };
    constexpr int length = sizeof(ns) / sizeof(int);

    zero(ns, length);

    for (int i = 0; i != length; ++i)
    {
        REQUIRE(ns[i] == 0);
    }
}

TEST_CASE("Zeroing { 1, 1 }")
{
    int ns[] = { 1, 1 };
    constexpr int length = sizeof(ns) / sizeof(int);

    zero(ns, length);

    for (int i = 0; i != length; ++i)
    {
        REQUIRE(ns[i] == 0);
    }
}

TEST_CASE("Zeroing { 1, 2 }")
{
    int ns[] = { 1, 2 };
    constexpr int length = sizeof(ns) / sizeof(int);

    zero(ns, length);

    for (int i = 0; i != length; ++i)
    {
        REQUIRE(ns[i] == 0);
    }
}

TEST_CASE("Zeroing { 1, 2, 3, 4, 5 }")
{
    int ns[] = { 1, 2, 3, 4, 5 };
    constexpr int length = sizeof(ns) / sizeof(int);

    zero(ns, length);

    for (int i = 0; i != length; ++i)
    {
        REQUIRE(ns[i] == 0);
    }
}

TEST_CASE("Zeroing 4 first elements of { 1, 2, 3, 4, 5 }")
{
    int ns[] = { 1, 2, 3, 4, 5 };
    constexpr int length = sizeof(ns) / sizeof(int) - 1;

    zero(ns, length);

    for (int i = 0; i != length; ++i)
    {
        REQUIRE(ns[i] == 0);
    }

    REQUIRE(ns[4] == 5);
}