#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "solution.h"


TEST_CASE("Most frequent in {1}")
{
    int ns[] = { 1 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 1);
}

TEST_CASE("Most frequent in {1, 1}")
{
    int ns[] = { 1, 1 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 1);
}

TEST_CASE("Most frequent in {1, 1, 1}")
{
    int ns[] = { 1, 1, 1 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 1);
}

TEST_CASE("Most frequent in {1, 2, 2}")
{
    int ns[] = { 1, 2, 2 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 2);
}

TEST_CASE("Most frequent in {1, 2, 2, 3, 3, 3}")
{
    int ns[] = { 1, 2, 2, 3, 3, 3 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 3);
}

TEST_CASE("Most frequent in {1, 3, 2, 3, 2, 3}")
{
    int ns[] = { 1, 3, 2, 3, 2, 3 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 3);
}

TEST_CASE("Most frequent in {6, 2, 7, 5, 2, 7, 5}")
{
    int ns[] = { 6, 2, 7, 5, 2, 7, 5 };

    REQUIRE(most_frequent(ns, sizeof(ns) / sizeof(int)) == 2);
}
