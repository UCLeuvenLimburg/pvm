#include "uniq.h"
#include "../Catch.h"
#include <set>

void test(std::vector<int>& ns, const std::set<int>& expected)
{
    uniq(&ns);
    std::set<int> actual(ns.begin(), ns.end());

    REQUIRE(actual == expected);
}

#define ARRAY(...)          __VA_ARGS__
#define TEST(NS, EXPECTED)  TEST_CASE("Uniq of {" #NS "}") { std::vector<int> ns { NS }; std::set<int> expected { EXPECTED }; test(ns, expected); }

TEST(ARRAY(), ARRAY())
TEST(ARRAY(1), ARRAY(1))
TEST(ARRAY(1, 1), ARRAY(1))
TEST(ARRAY(1, 1, 1), ARRAY(1))
TEST(ARRAY(1, 1, 1, 2), ARRAY(1, 2))
TEST(ARRAY(1, 1, 1, 2, 2), ARRAY(1, 2))
TEST(ARRAY(1, 2, 1, 2, 1), ARRAY(1, 2))
TEST(ARRAY(1, 2, 3, 2, 1), ARRAY(1, 2, 3))
