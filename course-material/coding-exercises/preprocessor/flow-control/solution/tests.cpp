#define CATCH_CONFIG_MAIN
#include "flow-control.h"
#include "catch.h"


TEST_CASE("UNLESS(true)")
{
    bool b = false;

    UNLESS(true)
    {
        b = true;
    }

    CHECK(b == false);
}

TEST_CASE("UNLESS(false)")
{
    bool b = false;

    UNLESS(false)
    {
        b = true;
    }

    CHECK(b == true);
}

TEST_CASE("UNLESS(true || true)")
{
    bool b = false;

    UNLESS(true || true)
    {
        b = true;
    }

    CHECK(b == false);
}

TEST_CASE("REPEAT")
{
    int x = 0;

    REPEAT
    {
        x++;

        if (x == 1000) break;
    }

    CHECK(x == 1000);
}

TEST_CASE("UNTIL")
{
    int x = 0;

    UNTIL(x == 10)
    {
        x++;
    }
    
    CHECK(x == 10);
}

TEST_CASE("UNTIL(true || false)")
{
    UNTIL(false || true)
    {
        REQUIRE(false);
    }
}
