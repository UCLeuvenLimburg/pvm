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

#define TEST_RANGE
#define TEST_COPY_LIST
#define TEST_PREPEND
#define TEST_APPEND






#define LLP(...)         create_linked_list(std::vector<int> { __VA_ARGS__ })
#define LL(...)          LLP(__VA_ARGS__).get()
#define CAT(a, b)        CAT2(a, b)
#define CAT2(a, b)       a ## b
#define DEFLL(var, ...)  auto CAT(_lst, __LINE__) = LLP(__VA_ARGS__); auto var = CAT(_lst, __LINE__).get()

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


#ifdef TEST_RANGE

TEST_CASE("range(1, 1)")
{
    auto actual = range(1, 1);

    check_equal(std::vector<int>{}, actual);
}

TEST_CASE("range(1, 2)")
{
    auto actual = range(1, 2);

    check_equal(std::vector<int>{1}, actual);
}

TEST_CASE("range(1, 3)")
{
    auto actual = range(1, 3);

    check_equal(std::vector<int>{1, 2}, actual);
}

TEST_CASE("range(0, 6)")
{
    auto actual = range(0, 6);

    check_equal(std::vector<int>{0, 1, 2, 3, 4, 5}, actual);
}

TEST_CASE("range(1, 0)")
{
    auto actual = range(1, 0);

    check_equal(std::vector<int>{}, actual);
}

#endif

#ifdef TEST_COPY_LIST

TEST_CASE("copy_list({})")
{
    DEFLL(original);
    std::vector<int> expected{ };
    auto actual = copy_list(original);

    check_equal(expected, actual);
}

TEST_CASE("copy_list({1})")
{
    DEFLL(original, 1);
    std::vector<int> expected{ 1 };
    auto actual = copy_list(original);

    REQUIRE(actual != original);
    check_equal(expected, actual);
}

TEST_CASE("copy_list({1, 2})")
{
    DEFLL(original, 1, 2);
    std::vector<int> expected{ 1, 2 };
    auto actual = copy_list(original);

    REQUIRE(actual != original);
    check_equal(expected, actual);
}

TEST_CASE("copy_list({1, 2, 3})")
{
    DEFLL(original, 1, 2, 3);
    std::vector<int> expected{ 1, 2, 3 };
    auto actual = copy_list(original);

    REQUIRE(actual != original);
    check_equal(expected, actual);
}

TEST_CASE("copy_list({1, 1, 1, 1, 1})")
{
    DEFLL(original, 1, 1, 1, 1, 1);
    std::vector<int> expected{ 1, 1, 1, 1, 1 };
    auto actual = copy_list(original);

    REQUIRE(actual != original);
    check_equal(expected, actual);
}

#endif

#ifdef TEST_PREPEND

TEST_CASE("prepend({}, 1)")
{
    DEFLL(list);
    auto original = list;

    prepend(&list, 1);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 1 }, list);
    CHECK(list->next == original);
}

TEST_CASE("prepend({2}, 1)")
{
    DEFLL(list, 2);
    auto original = list;

    prepend(&list, 1);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 1, 2 }, list);
    CHECK(list->next == original);
}

TEST_CASE("prepend({5, 1, 3, 2}, 9)")
{
    DEFLL(list, 5, 1, 3, 2);
    auto original = list;

    prepend(&list, 9);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 9, 5, 1, 3, 2 }, list);
    CHECK(list->next == original);
}

#endif

#ifdef TEST_APPEND

TEST_CASE("append({}, 1)")
{
    DEFLL(list);

    append(&list, 1);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 1 }, list);
}

TEST_CASE("append({1}, 2)")
{
    DEFLL(list, 1);
    auto original = list;

    append(&list, 2);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 1, 2 }, list);
    CHECK(original == list);
}

TEST_CASE("append({4, 4, 4}, 4)")
{
    DEFLL(list, 4, 4, 4);
    auto original = list;

    append(&list, 4);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 4, 4, 4, 4 }, list);
    CHECK(original == list);
}

TEST_CASE("append({5, 2, 3, 1}, 8)")
{
    DEFLL(list, 5, 2, 3, 1);
    auto original = list;

    append(&list, 8);

    REQUIRE(list != nullptr);
    check_equal(std::vector<int> { 5, 2, 3, 1, 8 }, list);
    CHECK(original == list);
}

#endif
