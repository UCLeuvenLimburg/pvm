#include "rotate.h"
#include "../Catch.h"

TEST_CASE("Rotating {} by 0")
{
    std::vector<int> ns{};
    int delta = 0;
    std::vector<int> expected{};

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {} by 1")
{
    std::vector<int> ns{};
    int delta = 1;
    std::vector<int> expected{};

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1} by 0")
{
    std::vector<int> ns{ 1 };
    int delta = 0;
    std::vector<int> expected{ 1 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1} by 1")
{
    std::vector<int> ns{ 1 };
    int delta = 1;
    std::vector<int> expected{ 1 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2} by 0")
{
    std::vector<int> ns{ 1, 2 };
    int delta = 0;
    std::vector<int> expected{ 1, 2 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2} by 1")
{
    std::vector<int> ns{ 1, 2 };
    int delta = 1;
    std::vector<int> expected{ 2, 1 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2} by -1")
{
    std::vector<int> ns{ 1, 2 };
    int delta = -1;
    std::vector<int> expected{ 2, 1 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2} by 2")
{
    std::vector<int> ns{ 1, 2 };
    int delta = 2;
    std::vector<int> expected{ 1, 2 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by 0")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = 0;
    std::vector<int> expected{ 1, 2, 3, 4, 5 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -1")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -1;
    std::vector<int> expected{ 2, 3, 4, 5, 1 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by 1")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = 1;
    std::vector<int> expected{ 5, 1, 2, 3, 4 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -2")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -2;
    std::vector<int> expected{ 3, 4, 5, 1, 2 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -3")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -3;
    std::vector<int> expected{ 4, 5, 1, 2, 3 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -4")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -4;
    std::vector<int> expected{ 5, 1, 2, 3, 4 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -5")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -5;
    std::vector<int> expected{ 1, 2, 3, 4, 5 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -10")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -10;
    std::vector<int> expected{ 1, 2, 3, 4, 5 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}

TEST_CASE("Rotating {1, 2, 3, 4, 5} by -23")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = -23;
    std::vector<int> expected{ 4, 5, 1, 2, 3 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}


TEST_CASE("Rotating {1, 2, 3, 4, 5} by 12")
{
    std::vector<int> ns{ 1, 2, 3, 4, 5 };
    int delta = 12;
    std::vector<int> expected{ 4, 5, 1, 2, 3 };

    rotate(&ns, delta);

    REQUIRE(ns == expected);
}