#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <functional>


void countdown(int);

namespace solution
{
    void countdown(int);
}


std::string with_redirected_cout(std::function<void()> f)
{
    std::streambuf* old_cout = std::cout.rdbuf();
    std::ostringstream ss;
    std::cout.rdbuf(ss.rdbuf());

    f();

    std::cout.rdbuf(old_cout);

    return ss.str();
}

TEST_CASE("Counting down from 3")
{
    const int from = 3;
    auto expected = with_redirected_cout([=]() { solution::countdown(from); });
    auto actual = with_redirected_cout([=]() { countdown(from); });

    REQUIRE(expected == actual);
}

TEST_CASE("Counting down from 5")
{
    const int from = 5;
    auto expected = with_redirected_cout([=]() { solution::countdown(from); });
    auto actual = with_redirected_cout([=]() { countdown(from); });

    REQUIRE(expected == actual);
}

TEST_CASE("Counting down from 10")
{
    const int from = 10;
    auto expected = with_redirected_cout([=]() { solution::countdown(from); });
    auto actual = with_redirected_cout([=]() { countdown(from); });

    REQUIRE(expected == actual);
}