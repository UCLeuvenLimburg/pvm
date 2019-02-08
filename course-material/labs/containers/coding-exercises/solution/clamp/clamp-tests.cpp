#include "clamp.h"
#include "../Catch.h"
#include <vector>
#include <list>


TEST_CASE("Clamping vector {1, -1, 1}")
{
    std::vector<int> actual{ 1, -1, 1 };
    std::vector<int> expected{ 1, 0, 1 };

    clamp(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Clamping list {1, -1, 1}")
{
    std::list<int> actual{ 1, -1, 1 };
    std::list<int> expected{ 1, 0, 1 };

    clamp(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Clamping vector {1, -2, 3, -4, 5}")
{
    std::vector<int> actual{ 1, -2, 3, -4, 5 };
    std::vector<int> expected{ 1, 0, 3, 0, 5 };

    clamp(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Clamping list {1, -2, 3, -4, 5}")
{
    std::list<int> actual{ 1, -2, 3, -4, 5 };
    std::list<int> expected{ 1, 0, 3, 0, 5 };

    clamp(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}
