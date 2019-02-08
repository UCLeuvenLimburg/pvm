#define CATCH_CONFIG_MAIN
#include "swap.h"
#include "Catch.h"


void test(int x, int y)
{
    int a = x;
    int b = y;

    swap(&a, &b);

    REQUIRE(a == y);
    REQUIRE(b == x);
}


#define TEST(x, y) TEST_CASE("Swapping " #x " and " #y ) { test(x, y); }

TEST(0, 0)
TEST(0, 1)
TEST(1, 0)
TEST(5, 8)
