#define CATCH_CONFIG_MAIN
#include "util.h"
#include "Catch.h"


TEST_CASE("Max of 1, 2, 3")
{
    int x = 1, y = 2, z = 3;
    int* p = max(&x, &y, &z);

    REQUIRE(p == &z);
}

TEST_CASE("Max of 5, 2, 3")
{
    int x = 5, y = 2, z = 3;
    int* p = max(&x, &y, &z);

    REQUIRE(p == &x);
}

TEST_CASE("Max of 5, 7, 3")
{
    int x = 5, y = 7, z = 3;
    int* p = max(&x, &y, &z);

    REQUIRE(p == &y);
}

TEST_CASE("Min/Max of 1, 2, 3")
{
    int x = 1, y = 2, z = 3;
    int *p, *q;

    minmax(&x, &y, &z, &p, &q);

    REQUIRE(p == &x);
    REQUIRE(q == &z);
}

TEST_CASE("Min/Max of 3, 2, 1")
{
    int x = 3, y = 2, z = 1;
    int *p, *q;

    minmax(&x, &y, &z, &p, &q);

    REQUIRE(p == &z);
    REQUIRE(q == &x);
}

TEST_CASE("Min/Max of 3, 5, 1")
{
    int x = 3, y = 5, z = 1;
    int *p, *q;

    minmax(&x, &y, &z, &p, &q);

    REQUIRE(p == &z);
    REQUIRE(q == &y);
}

TEST_CASE("Min/Max of 3, 0, 1")
{
    int x = 3, y = 0, z = 1;
    int *p, *q;

    minmax(&x, &y, &z, &p, &q);

    REQUIRE(p == &y);
    REQUIRE(q == &x);
}

TEST_CASE("Min/Max of 5, 1, 9")
{
    int x = 5, y = 1, z = 9;
    int *p, *q;

    minmax(&x, &y, &z, &p, &q);

    REQUIRE(p == &y);
    REQUIRE(q == &z);
}

TEST_CASE("Swapping min/max in 1, 2, 3")
{
    int x = 1, y = 2, z = 3;

    swap_min_and_max(&x, &y, &z);

    REQUIRE(x == 3);
    REQUIRE(y == 2);
    REQUIRE(z == 1);
}

TEST_CASE("Swapping min/max in 4, 1, 9")
{
    int x = 4, y = 1, z = 9;

    swap_min_and_max(&x, &y, &z);

    REQUIRE(x == 4);
    REQUIRE(y == 9);
    REQUIRE(z == 1);
}

TEST_CASE("Swapping min/max in 8, 1, 5")
{
    int x = 8, y = 1, z = 5;

    swap_min_and_max(&x, &y, &z);

    REQUIRE(x == 1);
    REQUIRE(y == 8);
    REQUIRE(z == 5);
}
