#include "reverse.h"
#include "../Catch.h"
#include <vector>
#include <list>


TEST_CASE("Reversing vector {}")
{
    std::vector<int> actual{};
    std::vector<int> expected{};

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing vector {1}")
{
    std::vector<int> actual{1};
    std::vector<int> expected{1};

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing vector {1, 2}")
{
    std::vector<int> actual{ 1, 2 };
    std::vector<int> expected{ 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing vector {1, 2, 3}")
{
    std::vector<int> actual{ 1, 2, 3 };
    std::vector<int> expected{ 3, 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing vector {1, 2, 3, 4}")
{
    std::vector<int> actual{ 1, 2, 3, 4 };
    std::vector<int> expected{ 4, 3, 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing vector {1, 2, 3, 4, 5}")
{
    std::vector<int> actual{ 1, 2, 3, 4, 5 };
    std::vector<int> expected{ 5, 4, 3, 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {}")
{
    std::list<int> actual{};
    std::list<int> expected{};

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {1}")
{
    std::list<int> actual{ 1 };
    std::list<int> expected{ 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {1, 2}")
{
    std::list<int> actual{ 1, 2 };
    std::list<int> expected{ 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {1, 2, 3}")
{
    std::list<int> actual{ 1, 2, 3 };
    std::list<int> expected{ 3, 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {1, 2, 3, 4}")
{
    std::list<int> actual{ 1, 2, 3, 4 };
    std::list<int> expected{ 4, 3, 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {1, 2, 3, 4, 5}")
{
    std::list<int> actual{ 1, 2, 3, 4, 5 };
    std::list<int> expected{ 5, 4, 3, 2, 1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {'a', 'b', 'c'}")
{
    std::list<char> actual{ 'a', 'b', 'c' };
    std::list<char> expected{ 'c', 'b', 'a' };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}

TEST_CASE("Reversing list {1.0, 2.0, 3.0}")
{
    std::list<double> actual{ 1.1, 2.2, 3.3 };
    std::list<double> expected{ 3.3, 2.2, 1.1 };

    ::reverse(actual.begin(), actual.end());

    REQUIRE(actual == expected);
}
