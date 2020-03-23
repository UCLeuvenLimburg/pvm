#define CATCH_CONFIG_MAIN
#include "number-set.h"
#include "catch.h"
#include <set>


void add_elements(NumberSet& ns, const std::set<unsigned>& ks)
{
    for (auto k : ks)
    {
        ns.add(k);
    }
}

void check_elements(const NumberSet& set, const std::set<unsigned>& ks)
{
    for (unsigned i = 0; i != 32; ++i)
    {
        bool expected = ks.find(i) != ks.end();
        INFO("Checking set.contains(" << i << "), expecting " << (expected ? "true" : "false"));
        REQUIRE(set.contains(i) == expected);
    }
}


TEST_CASE("Empty set contains nothing")
{
    std::set<unsigned> xs{ };
    NumberSet set;

    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 0 }")
{
    std::set<unsigned> xs{ 0 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 0, 1 }")
{
    std::set<unsigned> xs{ 0, 1 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 1 }")
{
    std::set<unsigned> xs{ 1 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 31 }")
{
    std::set<unsigned> xs{ 31 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 0, 2, 4, 6 }")
{
    std::set<unsigned> xs{ 0, 2, 4, 6 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 1, 3, 4, 7, 8, 10 }")
{
    std::set<unsigned> xs{ 1, 3, 4, 7, 8, 10 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Checking elements of { 0, ..., 31 }")
{
    std::set<unsigned> xs{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
    NumberSet set;

    add_elements(set, xs);
    check_elements(set, xs);
}

TEST_CASE("Removing 0 from { 0 }")
{
    std::set<unsigned> original{ 0 };
    std::set<unsigned> after_removal{ };
    NumberSet set;

    add_elements(set, original);
    set.remove(0);
    check_elements(set, after_removal);
}

TEST_CASE("Removing 1 from { 0 }")
{
    std::set<unsigned> original{ 0 };
    std::set<unsigned> after_removal{ 0 };
    NumberSet set;

    add_elements(set, original);
    set.remove(1);
    check_elements(set, after_removal);
}

TEST_CASE("Removing 1 from { 0, 1, 2 }")
{
    std::set<unsigned> original{ 0, 1, 2 };
    std::set<unsigned> after_removal{ 0, 2 };
    NumberSet set;

    add_elements(set, original);
    set.remove(1);
    check_elements(set, after_removal);
}

TEST_CASE("Removing 20 from { 0, ..., 31 }")
{
    std::set<unsigned> original{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
    std::set<unsigned> after_removal{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
    NumberSet set;

    add_elements(set, original);
    set.remove(20);
    check_elements(set, after_removal);
}

TEST_CASE("Intersection of { } and { }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { } );
    add_elements(set2, std::set<unsigned> { });

    const NumberSet& s2 = set2;
    set1.intersection(s2);

    check_elements(set1, std::set<unsigned> { });
}

TEST_CASE("Intersection of { 0 } and { }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0 });
    add_elements(set2, std::set<unsigned> { });

    const NumberSet& s2 = set2;
    set1.intersection(s2);

    check_elements(set1, std::set<unsigned> { });
}

TEST_CASE("Intersection of { } and { 0 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { });
    add_elements(set2, std::set<unsigned> { 0 });

    const NumberSet& s2 = set2;
    set1.intersection(s2);

    check_elements(set1, std::set<unsigned> { });
}

TEST_CASE("Intersection of { 0 } and { 0 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0 });
    add_elements(set2, std::set<unsigned> { 0 });

    const NumberSet& s2 = set2;
    set1.intersection(s2);

    check_elements(set1, std::set<unsigned> { 0 });
}

TEST_CASE("Intersection of { 1, 2, 3 } and { 2, 3, 4 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 1, 2, 3 });
    add_elements(set2, std::set<unsigned> { 2, 3, 4 });

    const NumberSet& s2 = set2;
    set1.intersection(s2);

    check_elements(set1, std::set<unsigned> { 2, 3 });
}

TEST_CASE("Intersection of { 0 } and { 31 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0 });
    add_elements(set2, std::set<unsigned> { 31 });

    const NumberSet& s2 = set2;
    set1.intersection(s2);

    check_elements(set1, std::set<unsigned> { });
}

TEST_CASE("Union of { } and { }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { });
    add_elements(set2, std::set<unsigned> { });

    const NumberSet& s2 = set2;
    set1.union_with(s2);

    check_elements(set1, std::set<unsigned> { });
}

TEST_CASE("Union of { 0 } and { }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0 });
    add_elements(set2, std::set<unsigned> { });

    const NumberSet& s2 = set2;
    set1.union_with(s2);

    check_elements(set1, std::set<unsigned> { 0 });
}

TEST_CASE("Union of { } and { 0 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { });
    add_elements(set2, std::set<unsigned> { 0 });

    const NumberSet& s2 = set2;
    set1.union_with(s2);

    check_elements(set1, std::set<unsigned> { 0 });
}

TEST_CASE("Union of { 0 } and { 0 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0 });
    add_elements(set2, std::set<unsigned> { 0 });

    const NumberSet& s2 = set2;
    set1.union_with(s2);

    check_elements(set1, std::set<unsigned> { 0 });
}

TEST_CASE("Union of { 0, 1, 2, 3 } and { 2, 3, 4 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0, 1, 2, 3 });
    add_elements(set2, std::set<unsigned> { 2, 3, 4 });

    const NumberSet& s2 = set2;
    set1.union_with(s2);

    check_elements(set1, std::set<unsigned> { 0, 1, 2, 3, 4 });
}

TEST_CASE("Union of { 0, 5 } and { 2, 31 }")
{
    NumberSet set1, set2;

    add_elements(set1, std::set<unsigned> { 0, 5 });
    add_elements(set2, std::set<unsigned> { 2, 31 });

    const NumberSet& s2 = set2;
    set1.union_with(s2);

    check_elements(set1, std::set<unsigned> { 0, 2, 5, 31 });
}

TEST_CASE("Size of { }")
{
    NumberSet set;
    
    REQUIRE(set.size() == 0);
}

TEST_CASE("Size of { 0 }")
{
    NumberSet set;

    add_elements(set, std::set<unsigned> { 0 });

    REQUIRE(set.size() == 1);
}

TEST_CASE("Size of { 1 }")
{
    NumberSet set;

    add_elements(set, std::set<unsigned> { 1 });

    REQUIRE(set.size() == 1);
}

TEST_CASE("Size of { 0, 1 }")
{
    NumberSet set;

    add_elements(set, std::set<unsigned> { 0, 1 });

    REQUIRE(set.size() == 2);
}

TEST_CASE("Size of { 0, 5, 31 }")
{
    NumberSet set;

    add_elements(set, std::set<unsigned> { 0, 5, 31 });

    REQUIRE(set.size() == 3);
}

TEST_CASE("Size of { 0, ..., 31 }")
{
    NumberSet set;

    add_elements(set, std::set<unsigned> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 });

    REQUIRE(set.size() == 32);
}
