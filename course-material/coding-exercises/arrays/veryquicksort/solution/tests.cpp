#define CATCH_CONFIG_MAIN
#include "veryquicksort.h"
#include "catch.h"


TEST_CASE("Veryquicksorting {}")
{
    veryquicksort(nullptr, 0);
}

TEST_CASE("Veryquicksorting {1}")
{
    int ns[] = { 1 };
    int expected[] = { 1 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}

TEST_CASE("Veryquicksorting {1, 2}")
{
    int ns[] = { 1, 2 };
    int expected[] = { 1, 2 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}

TEST_CASE("Veryquicksorting {2, 1}")
{
    int ns[] = { 2, 1 };
    int expected[] = { 1, 2 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}

TEST_CASE("Veryquicksorting {1, 2, 1}")
{
    int ns[] = { 1, 2, 1 };
    int expected[] = { 1, 1, 2 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}

TEST_CASE("Veryquicksorting {5, 0, 1, 0}")
{
    int ns[] = { 5, 0, 1, 0 };
    int expected[] = { 0, 0, 1, 5 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}

TEST_CASE("Veryquicksorting {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}")
{
    int ns[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int expected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}

TEST_CASE("Veryquicksorting {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}")
{
    int ns[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int expected[] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9 };

    veryquicksort(ns, sizeof(ns) / sizeof(int));

    for (unsigned i = 0; i != sizeof(ns) / sizeof(int); ++i)
    {
        INFO("Comparing index " << i);
        REQUIRE(ns[i] == expected[i]);
    }
}
