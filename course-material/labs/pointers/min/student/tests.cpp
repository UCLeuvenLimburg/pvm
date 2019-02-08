#define CATCH_CONFIG_MAIN
#include "min.h"
#include "Catch.h"


TEST_CASE("Min of 1, 2, 3" ) 
{
    int x = 1, y = 2, z = 3;
    int* p = min(&x, &y, &z);

    REQUIRE(p == &x);
}

TEST_CASE("Min of 5, 2, 3")
{
    int x = 5, y = 2, z = 3;
    int* p = min(&x, &y, &z);

    REQUIRE(p == &y);
}

TEST_CASE("Min of 5, 7, 3")
{
    int x = 5, y = 7, z = 3;
    int* p = min(&x, &y, &z);

    REQUIRE(p == &z);
}
