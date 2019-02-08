#define CATCH_CONFIG_MAIN
#include "quotrest.h"
#include "Catch.h"


void test(int x, int y)
{
    int r, q;
    quotrest(x, y, &q, &r);
    INFO("q = " << q << ", r = " << r);
    REQUIRE(x == y * q + r);
}


#define TEST(x, y) TEST_CASE("Division of " #x " by " #y ) { test(x, y); }

TEST(1, 1)
TEST(5, 1)
TEST(8, 2)
TEST(8, 4)
TEST(0, 1)
TEST(8, 3)
TEST(97, 15)
