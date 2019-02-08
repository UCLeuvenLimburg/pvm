#include "max.h"
#include "../Catch.h"


TEST_CASE("Max of 2 mutable integers")
{
    int x = 1;
    int y = 2;
    
    CHECK(max(x, y) == 2);
    CHECK(max(y, x) == 2);
}

TEST_CASE("Modifying max of 2 mutable integers")
{
    int x = 9;
    int y = 5;

    max(x, y)++;

    CHECK(x == 10);
    CHECK(y == 5);
}

TEST_CASE("Max of 2 const integers")
{
    const int x = 7;
    const int y = 4;

    CHECK(max(x, y) == 7);
    CHECK(max(y, x) == 7);
}

TEST_CASE("Max of 2 mutable integers returns reference to max")
{
    int x = 7;
    int y = 9;
    int& z = max(x, y);

    CHECK(&z == &y);
}

TEST_CASE("Max of 2 const integers returns reference to max")
{
    const int x = 2;
    const int y = 8;
    const int& z = max(x, y);

    CHECK(&z == &y);
}
