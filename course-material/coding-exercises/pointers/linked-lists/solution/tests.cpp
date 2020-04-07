#define CATCH_CONFIG_MAIN
#include "linked-list-operations.h"
#include "catch.h"
#include <memory>
#include <vector>



// --------------------------------------------------------
//
// --> Comment out these definitions to turn off tests <--
//
// --------------------------------------------------------

#define TEST_NTH_VALUE
#define TEST_LENGTH
#define TEST_SUM
#define TEST_LAST
#define TEST_PENULTIMATE
#define TEST_ZERO
#define TEST_CUMULATIVE
#define TEST_EQUAL







#define LLP(...)         create_linked_list(std::vector<int> { __VA_ARGS__ })
#define LL(...)          LLP(__VA_ARGS__).get()
#define DEFLL(var, ...)  auto _lst##__LINE__ = LLP(__VA_ARGS__); auto var = _lst##__LINE__.get()

void check_equal(const std::vector<int>& ns, const linked_list* start)
{
    const linked_list* current = start;

    for (auto n : ns)
    {
        REQUIRE(current != nullptr);
        CHECK(n == current->value);

        current = current->next;
    }

    CHECK(current == nullptr);
}

std::unique_ptr<linked_list> create_linked_list(const std::vector<int>& ns)
{
    linked_list* current = nullptr;

    for (auto rit = ns.rbegin(); rit != ns.rend(); ++rit)
    {
        current = new linked_list{ *rit, current };
    }

    return std::unique_ptr<linked_list>(current);
}

#ifdef TEST_NTH_VALUE

TEST_CASE("nth_value({1}, i)")
{
    CHECK(nth_value(LL(1), 0) == 1);
}

TEST_CASE("nth_value({2}, i)")
{
    CHECK(nth_value(LL(2), 0) == 2);
}

TEST_CASE("nth_value({1, 2}, i)")
{
    DEFLL(list, 1, 2);

    CHECK(nth_value(list, 0) == 1);
    CHECK(nth_value(list, 1) == 2);
}

TEST_CASE("nth_value({4, 2, 3, 1}, i)")
{
    DEFLL(list, 4, 2, 3, 1);

    CHECK(nth_value(list, 0) == 4);
    CHECK(nth_value(list, 1) == 2);
    CHECK(nth_value(list, 2) == 3);
    CHECK(nth_value(list, 3) == 1);
}

#endif

#ifdef TEST_LENGTH

TEST_CASE("length({})")
{
    CHECK(length(LL()) == 0);
}

TEST_CASE("length({1})")
{
    CHECK(length(LL(1)) == 1);
}

TEST_CASE("length({5})")
{
    CHECK(length(LL(5)) == 1);
}

TEST_CASE("length({5, 3, 4, 1})")
{
    CHECK(length(LL(5, 3, 4, 1)) == 4);
}

#endif

#ifdef TEST_SUM

TEST_CASE("sum({})")
{
    CHECK(sum(LL()) == 0);
}

TEST_CASE("sum({1})")
{
    CHECK(sum(LL(1)) == 1);
}

TEST_CASE("sum({5})")
{
    CHECK(sum(LL(5)) == 5);
}

TEST_CASE("sum({5, 3, 4, 1})")
{
    CHECK(sum(LL(5, 3, 4, 1)) == 5 + 3 + 4 + 1);
}

#endif

#ifdef TEST_LAST

TEST_CASE("last({})")
{
    DEFLL(list);

    CHECK(last(list) == nullptr);
}

TEST_CASE("last({1})")
{
    DEFLL(list, 1);

    CHECK(last(list) == list);
}

TEST_CASE("last({1, 2})")
{
    DEFLL(list, 1, 2);

    CHECK(last(list) == list->next);
}

TEST_CASE("last({3, 2, 1})")
{
    DEFLL(list, 3, 2, 1);

    CHECK(last(list) == list->next->next);
}

TEST_CASE("last({5, 5, 5, 5, 5})")
{
    DEFLL(list, 5, 5, 5, 5, 5);

    CHECK(last(list) == list->next->next->next->next);
}

#endif

#ifdef TEST_PENULTIMATE

TEST_CASE("penultimate({})")
{
    DEFLL(list);

    CHECK(penultimate(list) == nullptr);
}

TEST_CASE("penultimate({1})")
{
    DEFLL(list, 1);

    CHECK(penultimate(list) == nullptr);
}

TEST_CASE("penultimate({1, 2})")
{
    DEFLL(list, 1, 2);

    CHECK(penultimate(list) == list);
}

TEST_CASE("penultimate({3, 2, 1})")
{
    DEFLL(list, 3, 2, 1);

    CHECK(penultimate(list) == list->next);
}

TEST_CASE("penultimate({5, 5, 5, 5, 5})")
{
    DEFLL(list, 5, 5, 5, 5, 5);

    CHECK(penultimate(list) == list->next->next->next);
}

#endif

#ifdef TEST_ZERO

TEST_CASE("zero({})")
{
    DEFLL(list);
    std::vector<int> ns{ };

    zero(list);

    check_equal(ns, list);
}

TEST_CASE("zero({1})")
{
    DEFLL(list, 1);
    std::vector<int> ns{ 0 };

    zero(list);

    check_equal(ns, list);
}

TEST_CASE("zero({1, 2})")
{
    DEFLL(list, 1, 2);
    std::vector<int> ns{ 0, 0 };

    zero(list);

    check_equal(ns, list);
}

TEST_CASE("zero({5, 5, 5, 5, 5})")
{
    DEFLL(list, 5, 5, 5, 5, 5);
    std::vector<int> ns{ 0, 0, 0, 0, 0 };

    zero(list);

    check_equal(ns, list);
}

#endif

#ifdef TEST_CUMULATIVE

TEST_CASE("cumulative({})")
{
    DEFLL(list);
    std::vector<int> ns{ };

    cumulative(list);

    check_equal(ns, list);
}

TEST_CASE("cumulative({1})")
{
    DEFLL(list, 1);
    std::vector<int> ns{ 1 };

    cumulative(list);

    check_equal(ns, list);
}

TEST_CASE("cumulative({1, 2})")
{
    DEFLL(list, 1, 2);
    std::vector<int> ns{ 1, 3 };

    cumulative(list);

    check_equal(ns, list);
}

TEST_CASE("cumulative({1, 2, 3, 4})")
{
    DEFLL(list, 1, 2, 3, 4);
    std::vector<int> ns{ 1, 3, 6, 10 };

    cumulative(list);

    check_equal(ns, list);
}

TEST_CASE("cumulative({1, 1, 1, 1, 1})")
{
    DEFLL(list, 1, 1, 1, 1, 1);
    std::vector<int> ns{ 1, 2, 3, 4, 5 };

    cumulative(list);

    check_equal(ns, list);
}

TEST_CASE("cumulative({5, 5, 5, 5, 5})")
{
    DEFLL(list, 5, 5, 5, 5, 5);
    std::vector<int> ns{ 5, 10, 15, 20, 25 };

    cumulative(list);

    check_equal(ns, list);
}

TEST_CASE("cumulative({1, -1, 1, -1})")
{
    DEFLL(list, 1, -1, 1, -1);
    std::vector<int> ns{ 1, 0, 1, 0 };

    cumulative(list);

    check_equal(ns, list);
}

#endif

#ifdef TEST_EQUAL

TEST_CASE("equal({}, {})")
{
    CHECK(equal(LL(), LL()));
}

TEST_CASE("equal({}, {1})")
{
    CHECK(!equal(LL(), LL(1)));
}

TEST_CASE("equal({1}, {})")
{
    CHECK(!equal(LL(1), LL()));
}

TEST_CASE("equal({1}, {1})")
{
    CHECK(equal(LL(1), LL(1)));
}

TEST_CASE("equal({1}, {2})")
{
    CHECK(!equal(LL(1), LL(2)));
}

TEST_CASE("equal({5, 3, 4, 2, 1}, {5, 3, 4, 2, 1})")
{
    CHECK(equal(LL(5, 3, 4, 2, 1), LL(5, 3, 4, 2, 1)));
}

TEST_CASE("equal({5, 3, 4, 2, 1}, {5, 3, 4, 2, 1, 9})")
{
    CHECK(!equal(LL(5, 3, 4, 2, 1), LL(5, 3, 4, 2, 1, 9)));
}

TEST_CASE("equal({5, 3, 4, 2, 1, 9}, {5, 3, 4, 2, 1})")
{
    CHECK(!equal(LL(5, 3, 4, 2, 1, 9), LL(5, 3, 4, 2, 1)));
}

TEST_CASE("equal({5, 3, 4, 2, 1}, {5, 3, 2, 4, 1})")
{
    CHECK(!equal(LL(5, 3, 4, 2, 1), LL(5, 3, 2, 4, 1)));
}


#endif
