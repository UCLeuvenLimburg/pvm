#include "split.h"
#include "../Catch.h"


TEST_CASE("Splitting {}")
{
    int *odds, *evens;
    unsigned n_odds, n_evens;

    split(nullptr, 0, &odds, &n_odds, &evens, &n_evens);

    REQUIRE(n_odds == 0);
    REQUIRE(n_evens == 0);

    delete[] odds;
    delete[] evens;
}

TEST_CASE("Splitting {1, 2}")
{
    int ns[] = { 1, 2 };
    int *odds, *evens;
    unsigned n_odds, n_evens;
    int expected_odds[] = { 1 };
    int expected_evens[] = { 2 };

    split(ns, sizeof(ns) / sizeof(int), &odds, &n_odds, &evens, &n_evens);

    REQUIRE(n_odds == sizeof(expected_odds)/sizeof(int));
    REQUIRE(n_evens == sizeof(expected_evens)/sizeof(int));

    for (unsigned i = 0; i != sizeof(expected_odds) / sizeof(int); ++i)
    {
        REQUIRE(odds[i] == expected_odds[i]);
        REQUIRE(evens[i] == expected_evens[i]);
    }

    delete[] odds;
    delete[] evens;
}

TEST_CASE("Splitting {2, 1}")
{
    int ns[] = { 2, 1 };
    int *odds, *evens;
    unsigned n_odds, n_evens;
    int expected_odds[] = { 1 };
    int expected_evens[] = { 2 };

    split(ns, sizeof(ns) / sizeof(int), &odds, &n_odds, &evens, &n_evens);

    REQUIRE(n_odds == sizeof(expected_odds) / sizeof(int));
    REQUIRE(n_evens == sizeof(expected_evens) / sizeof(int));

    for (unsigned i = 0; i != sizeof(expected_odds) / sizeof(int); ++i)
    {
        REQUIRE(odds[i] == expected_odds[i]);
        REQUIRE(evens[i] == expected_evens[i]);
    }

    delete[] odds;
    delete[] evens;
}

TEST_CASE("Splitting {1, 2, 3, 4}")
{
    int ns[] = { 1, 2, 3, 4 };
    int *odds, *evens;
    unsigned n_odds, n_evens;
    int expected_odds[] = { 1, 3 };
    int expected_evens[] = { 2, 4 };

    split(ns, sizeof(ns) / sizeof(int), &odds, &n_odds, &evens, &n_evens);

    REQUIRE(n_odds == sizeof(expected_odds) / sizeof(int));
    REQUIRE(n_evens == sizeof(expected_evens) / sizeof(int));

    for (unsigned i = 0; i != sizeof(expected_odds) / sizeof(int); ++i)
    {
        REQUIRE(odds[i] == expected_odds[i]);
        REQUIRE(evens[i] == expected_evens[i]);
    }

    delete[] odds;
    delete[] evens;
}

TEST_CASE("Splitting {4, 7, 5, 8}")
{
    int ns[] = { 4, 7, 5, 8 };
    int *odds, *evens;
    unsigned n_odds, n_evens;
    int expected_odds[] = { 7, 5 };
    int expected_evens[] = { 4, 8 };

    split(ns, sizeof(ns) / sizeof(int), &odds, &n_odds, &evens, &n_evens);

    REQUIRE(n_odds == sizeof(expected_odds) / sizeof(int));
    REQUIRE(n_evens == sizeof(expected_evens) / sizeof(int));

    for (unsigned i = 0; i != sizeof(expected_odds) / sizeof(int); ++i)
    {
        REQUIRE(odds[i] == expected_odds[i]);
        REQUIRE(evens[i] == expected_evens[i]);
    }

    delete[] odds;
    delete[] evens;
}

TEST_CASE("Splitting {8, 4, 3, 3, 8, 1}")
{
    int ns[] = { 8, 4, 3, 3, 8, 1 };
    int *odds, *evens;
    unsigned n_odds, n_evens;
    int expected_odds[] = { 3, 3, 1 };
    int expected_evens[] = { 8, 4, 8 };

    split(ns, sizeof(ns) / sizeof(int), &odds, &n_odds, &evens, &n_evens);

    REQUIRE(n_odds == sizeof(expected_odds) / sizeof(int));
    REQUIRE(n_evens == sizeof(expected_evens) / sizeof(int));

    for (unsigned i = 0; i != sizeof(expected_odds) / sizeof(int); ++i)
    {
        REQUIRE(odds[i] == expected_odds[i]);
        REQUIRE(evens[i] == expected_evens[i]);
    }

    delete[] odds;
    delete[] evens;
}
