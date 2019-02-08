#include "swap.h"
#include "../Catch.h"


TEST_CASE("Swapping 0 and 1")
{
    int x = 0, y = 1;
    swap(x, y);

    REQUIRE(x == 1);
    REQUIRE(y == 0);
}

TEST_CASE("Swapping 1 and 5")
{
    int x = 1, y = 5;
    swap(x, y);

    REQUIRE(x == 5);
    REQUIRE(y == 1);
}
