#include "person.h"
#include "../Catch.h"
#include <algorithm>


template<typename T>
bool contains(std::vector<T> xs, const T& x)
{
    return std::find(xs.begin(), xs.end(), x) != xs.end();
}


TEST_CASE("Getting name")
{
    const Person p("Roger");
    
    REQUIRE(p.get_name() == "Roger");
}

TEST_CASE("Getting grandchildren")
{
    Person grandfather("a");
    Person grandmother("b");
    Person mother("c", &grandmother, &grandfather);
    Person father("d", &grandmother, &grandfather);
    Person child1("e", nullptr, &father);
    Person child2("e", nullptr, &father);
    Person child3("f", &mother, nullptr);
    Person child4("g", &father, nullptr);

    const Person& gp = grandfather;

    auto grandchildren = gp.get_grandchildren();

    REQUIRE(grandchildren.size() == 4);
    CHECK(contains(grandchildren, &child1));
    CHECK(contains(grandchildren, &child2));
    CHECK(contains(grandchildren, &child3));
    CHECK(contains(grandchildren, &child4));
}

TEST_CASE("isAncestor")
{
    Person grandfather("a");
    Person grandmother("b");
    Person mother("c", &grandmother, &grandfather);
    Person father("d", &grandmother, &grandfather);
    Person child1("e", nullptr, &father);
    Person child2("e", nullptr, &father);
    Person child3("f", &mother, nullptr);
    Person child4("g", &father, nullptr);

    const Person& gf = grandfather;
    const Person& gm = grandmother;
    const Person& m = mother;
    const Person& f = father;
    const Person& c1 = child1;
    const Person& c4 = child4;

    CHECK(!c1.is_ancestor(m));
    CHECK(c1.is_ancestor(f));
    CHECK(c4.is_ancestor(gf));
    CHECK(!c4.is_ancestor(c4));
    CHECK(!f.is_ancestor(c4));
}

TEST_CASE("is")
{
    Person grandfather("a");
    Person grandmother("b");
    Person mother("c", &grandmother, &grandfather);
    Person father("d", &grandmother, &grandfather);
    Person child1("e", nullptr, &father);
    Person child2("e", nullptr, &father);
    Person child3("f", &mother, nullptr);
    Person child4("g", &father, nullptr);

    const Person& gf = grandfather;
    const Person& gm = grandmother;
    const Person& m = mother;
    const Person& f = father;
    const Person& c1 = child1;
    const Person& c4 = child4;

    CHECK(gf.is_descendant(c1));
    CHECK(gf.is_descendant(c4));
    CHECK(gm.is_descendant(c1));
    CHECK(gm.is_descendant(c4));
    CHECK(!m.is_descendant(c1));
    CHECK(f.is_descendant(c1));
}