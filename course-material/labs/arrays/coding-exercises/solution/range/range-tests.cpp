#include "range.h"
#include "../Catch.h"


TEST_CASE("Range from 0 to 1")
{
    int from = 0, to = 1;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from 0 to 2")
{
    int from = 0, to = 2;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from 1 to 2")
{
    int from = 1, to = 2;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from 0 to 5")
{
    int from = 0, to = 5;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from 0 to 10")
{
    int from = 0, to = 10;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from 0 to 100")
{
    int from = 0, to = 100;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from 10 to 100")
{
    int from = 10, to = 100;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}

TEST_CASE("Range from -5 to 0")
{
    int from = -5, to = 0;
    int expected_size = to - from + 1;
    int* actual = range(from, to);

    for (int i = 0; i != expected_size; ++i)
    {
        INFO("Comparing at index " << i);
        REQUIRE(actual[i] == from + i);
    }
}