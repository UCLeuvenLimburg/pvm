#include "counter.h"
#include "../Catch.h"
#include <numeric>


TEST_CASE("Counter initialised to 0")
{
    Counter c;

    REQUIRE(c.getValue() == 0);
}

TEST_CASE("Const Counter's getValue is accessible")
{
    const Counter c;

    REQUIRE(c.getValue() == 0);
}

TEST_CASE("Setting Counter")
{
    Counter c;

    c.setValue(5);

    REQUIRE(c.getValue() == 5);
}

TEST_CASE("Incrementing Counter")
{
    Counter c;

    REQUIRE(c.getValue() == 0);
    c.increment();
    REQUIRE(c.getValue() == 1);
}

TEST_CASE("Resetting Counter")
{
    Counter c;

    c.setValue(11);
    REQUIRE(c.getValue() == 11);
    c.reset();
    REQUIRE(c.getValue() == 0);
}

TEST_CASE("Counter must work with unsigned")
{
    Counter c;
    c.setValue(std::numeric_limits<unsigned>::max());

    int64_t value = c.getValue();

    REQUIRE(value == std::numeric_limits<unsigned>::max());
}