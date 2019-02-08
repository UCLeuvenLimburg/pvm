#define CATCH_CONFIG_MAIN
#include "linked_list.h"
#include "Catch.h"
#include <vector>
#include <memory>


void destroy(linked_list* lst)
{
    linked_list* next;

    while (lst != nullptr)
    {
        next = lst->next;
        delete lst;
        lst = next;
    }
}

std::shared_ptr<linked_list> create(const std::vector<int>& xs)
{
    linked_list* result = nullptr;

    for (auto i = xs.rbegin(); i != xs.rend(); ++i)
    {
        result = new linked_list{ *i, result };
    }

    return std::shared_ptr<linked_list>(result, destroy);
}




TEST_CASE("Length of empty list")
{
    std::vector<int> ns{};
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Length of {1}")
{
    std::vector<int> ns{ 1 };
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Length of {1, 2}")
{
    std::vector<int> ns{ 1, 2 };
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Length of {1, 2, 3}")
{
    std::vector<int> ns{ 1, 2, 3 };
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Penultimate of {}")
{
    REQUIRE(penultimate(nullptr) == nullptr);
}

TEST_CASE("Penultimate of {1}")
{
    linked_list a{ 1, nullptr };

    REQUIRE(penultimate(&a) == nullptr);
}

TEST_CASE("Penultimate of {1, 2}")
{
    linked_list b{ 2, nullptr };
    linked_list a{ 1, &b };

    REQUIRE(penultimate(&a) == &a);
}

TEST_CASE("Penultimate of {1, 2, 3}")
{
    linked_list c{ 3, nullptr };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };

    REQUIRE(penultimate(&a) == &b);
}

TEST_CASE("Penultimate of {1, 2, 3, 4}")
{
    linked_list d{ 4, nullptr };
    linked_list c{ 3, &d };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };

    REQUIRE(penultimate(&a) == &c);
}

TEST_CASE("Longest of {} and {}")
{
    std::vector<int> ns{};
    std::vector<int> ms{};
    auto l1 = create(ns);
    auto l2 = create(ms);

    REQUIRE(longest(l1.get(), l2.get()) == nullptr);
}

TEST_CASE("Longest of {1,2,3} and {}")
{
    std::vector<int> ns{ 1,2,3 };
    std::vector<int> ms{};
    auto l1 = create(ns);
    auto l2 = create(ms);

    REQUIRE(longest(l1.get(), l2.get()) == l1.get());
}

TEST_CASE("Longest of {} and {1,2,3}")
{
    std::vector<int> ns{};
    std::vector<int> ms{ 1,2,3 };
    auto l1 = create(ns);
    auto l2 = create(ms);

    REQUIRE(longest(l1.get(), l2.get()) == l2.get());
}

TEST_CASE("Longest of {1} and {1,2,3}")
{
    std::vector<int> ns{ 1 };
    std::vector<int> ms{ 1,2,3 };
    auto l1 = create(ns);
    auto l2 = create(ms);

    REQUIRE(longest(l1.get(), l2.get()) == l2.get());
}

TEST_CASE("Longest of {1,2,[3,4]} and {1,2,3}")
{
    linked_list d{ 4, nullptr };
    linked_list c{ 3, &d };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    d.next = &c;

    std::vector<int> ms{ 1,2,3 };
    auto l2 = create(ms);

    REQUIRE(longest(&a, l2.get()) == &a);
}

TEST_CASE("Making {1} cyclic")
{
    linked_list a{ 1, nullptr };

    make_cyclic(&a);

    REQUIRE(a.next == &a);
}

TEST_CASE("Making {1, 2} cyclic")
{
    linked_list b{ 2, nullptr };
    linked_list a{ 1, &b };

    make_cyclic(&a);

    REQUIRE(a.next == &b);
    REQUIRE(b.next == &a);
}

TEST_CASE("Making {1, 2, 3} cyclic")
{
    linked_list c{ 3, nullptr };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };

    make_cyclic(&a);

    REQUIRE(a.next == &b);
    REQUIRE(b.next == &c);
    REQUIRE(c.next == &a);
}

TEST_CASE("{} has no cycle")
{
    std::vector<int> ns{};
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{1} has no cycle")
{
    std::vector<int> ns{ 1 };
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{1, 2} has no cycle")
{
    std::vector<int> ns{ 1, 2 };
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{1, 2, 3} has no cycle")
{
    std::vector<int> ns{ 1, 2, 3 };
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{[1]} has a cycle")
{
    linked_list a{ 1, nullptr };
    a.next = &a;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{[1, 2]} has a cycle")
{
    linked_list b{ 2, nullptr };
    linked_list a{ 1, &b };
    b.next = &a;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{[1, 2, 3]} has a cycle")
{
    linked_list c{ 3, nullptr };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    c.next = &a;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, 2, [3]} has a cycle")
{
    linked_list c{ 3, nullptr };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    c.next = &c;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, [2, 3]} has a cycle")
{
    linked_list c{ 3, nullptr };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    c.next = &b;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, [2, 3, 4]} has a cycle")
{
    linked_list d{ 4, nullptr };
    linked_list c{ 3, &d };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    d.next = &b;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, 2, [3, 4]} has a cycle")
{
    linked_list d{ 4, nullptr };
    linked_list c{ 3, &d };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    d.next = &c;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, 2, 3, [4]} has a cycle")
{
    linked_list d{ 4, nullptr };
    linked_list c{ 3, &d };
    linked_list b{ 2, &c };
    linked_list a{ 1, &b };
    d.next = &d;

    REQUIRE(has_cycle(&a));
}
