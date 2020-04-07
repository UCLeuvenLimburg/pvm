#define CATCH_CONFIG_MAIN
#include "interval.h"
#include "catch.h"


TEST_CASE("Creation")
{
    const double lower = 1;
    const double upper = 5;
    Interval i(lower, upper);

    CHECK(i.lower_bound() == lower);
    CHECK(i.upper_bound() == upper);
}

TEST_CASE("Contains")
{
    const double lower = 7;
    const double upper = 10;
    Interval i(lower, upper);

    CHECK(i.contains(7.1));
    CHECK(i.contains(8));
    CHECK(i.contains(9.9));

    CHECK(!i.contains(6.9));
    CHECK(!i.contains(10.1));
}

TEST_CASE("Setting lower bound")
{
    const double lower = 7;
    const double new_lower = 1;
    const double upper = 10;
    Interval i(lower, upper);

    CHECK(i.lower_bound() == lower);
    CHECK(i.upper_bound() == upper);
    i.set_lower_bound(new_lower);
    CHECK(i.lower_bound() == new_lower);
    CHECK(i.upper_bound() == upper);
}

TEST_CASE("Setting upper bound")
{
    const double lower = 7;
    const double upper = 10;
    const double new_upper = 15;
    Interval i(lower, upper);

    CHECK(i.lower_bound() == lower);
    CHECK(i.upper_bound() == upper);
    i.set_upper_bound(new_upper);
    CHECK(i.lower_bound() == lower);
    CHECK(i.upper_bound() == new_upper);
}

TEST_CASE("Const correctness")
{
    const double lower = 1;
    const double upper = 5;
    const Interval i(lower, upper);

    CHECK(i.lower_bound() == lower);
    CHECK(i.upper_bound() == upper);
    CHECK(i.contains((lower + upper) / 2));
}
