#define CATCH_CONFIG_MAIN
#include "repeat-n.h"
#include "catch.h"


TEST_CASE("REPEAT_N(5)")
{
    int i = 0;

    REPEAT_N(5)
    {
        i++;
    }

    CHECK(i == 5);
}

TEST_CASE("REPEAT_N(5); REPEAT_N(5)")
{
    int i = 0;

    REPEAT_N(5)
    {
        i++;
    }

    REPEAT_N(5)
    {
        i++;
    }

    CHECK(i == 10);
}

TEST_CASE("Sequence")
{
    int i = 0;

    REPEAT_N(3)
    {
        i++;
    }

    REPEAT_N(5)
    {
        i++;
    }

    CHECK(i == 8);
}

TEST_CASE("Nested")
{
    int i = 0;

    REPEAT_N(3)
    {
        REPEAT_N(5)
        {
            REPEAT_N(2)
            {
                i++;
            }
        }
    }

    CHECK(i == 3 * 5 * 2);
}
