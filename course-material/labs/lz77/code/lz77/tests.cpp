#ifdef TEST_BUILD
#define CATCH_CONFIG_MAIN
#include "lz77.h"
#include "Catch.h"


triplet t(unsigned distance, unsigned length, char c)
{
    return triplet{ distance, length, c };
}


TEST_CASE("match_length")
{
    CHECK(match_length("abc", "abc") == 3);
    CHECK(match_length("abc", "abcd") == 3);
    CHECK(match_length("abcd", "abc") == 3);
    CHECK(match_length("abc", "abce") == 3);
    CHECK(match_length("", "xyz") == 0);
    CHECK(match_length("x", "xyz") == 1);
    CHECK(match_length("xy", "xyz") == 2);
}

TEST_CASE("find_longest_match('abcabc', 3, 3)")
{
    unsigned distance, length;

    find_longest_match("abcabc", 3, 3, &distance, &length);

    CHECK(distance == 3);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('abcxabc', 4, 3)")
{
    unsigned distance, length;

    find_longest_match("abcxabc", 4, 3, &distance, &length);

    CHECK(distance == 4);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('abcxyz', 3, 3)")
{
    unsigned distance, length;

    find_longest_match("abcxyz", 3, 3, &distance, &length);

    CHECK(distance == 0);
    CHECK(length == 0);
}

TEST_CASE("find_longest_match('aaaa', 1, 5)")
{
    unsigned distance, length;

    find_longest_match("aaaa", 1, 5, &distance, &length);

    CHECK(distance == 1);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('abcdabcd', 4, 3)")
{
    unsigned distance, length;

    find_longest_match("abcdabcd", 4, 3, &distance, &length);

    CHECK(distance == 4);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('aababcabcdabcd', 10, 5)")
{
    unsigned distance, length;

    find_longest_match("aababcabcdabcd", 10, 5, &distance, &length);

    CHECK(distance == 4);
    CHECK(length == 4);
}

TEST_CASE("encode(10, 10, 'a')")
{
    std::string s = "a";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 1);
    CHECK(result[0] == t(0, 0, 'a'));
}

TEST_CASE("encode(10, 10, 'aa')")
{
    std::string s = "aa";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 2);
    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(0, 0, 'a'));
}

TEST_CASE("encode(10, 10, 'aaa')")
{
    std::string s = "aaa";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 2);

    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(1, 1, 'a'));
}

TEST_CASE("encode(10, 10, 'aaaa')")
{
    std::string s = "aaaa";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 2);
    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(1, 2, 'a'));
}

TEST_CASE("encode(10, 10, 'abcabcabc')")
{
    std::string s = "abcabcabc";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 4);
    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(0, 0, 'b'));
    CHECK(result[2] == t(0, 0, 'c'));
    CHECK(result[3] == t(3, 5, 'c'));
}

TEST_CASE("encode(10, 2, 'aaaaa')")
{
    std::string s = "aaaaa";
    auto result = encode(10, 2, s);

    REQUIRE(result.size() == 3);
    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(1, 2, 'a'));
    CHECK(result[2] == t(0, 0, 'a'));
}

TEST_CASE("encode(10, 3, 'aaaaa')")
{
    std::string s = "aaaaa";
    auto result = encode(10, 3, s);

    REQUIRE(result.size() == 2);
    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(1, 3, 'a'));
}

TEST_CASE("encode(2, 10, 'abbabbb')")
{
    std::string s = "abbabbb";
    auto result = encode(2, 10, s);

    REQUIRE(result.size() == 5);
    CHECK(result[0] == t(0, 0, 'a'));
    CHECK(result[1] == t(0, 0, 'b'));
    CHECK(result[2] == t(1, 1, 'a'));
    CHECK(result[3] == t(2, 1, 'b'));
    CHECK(result[4] == t(0, 0, 'b'));
}

TEST_CASE("decode(encode('a'))")
{
    const std::string string = "a";

    for (unsigned max_distance = 1; max_distance != 10; ++max_distance)
    {
        for (unsigned max_length = 1; max_length != 10; ++max_length)
        {
            auto triplets = encode(max_distance, max_length, string);
            auto decoded = decode(triplets);

            CHECK(decoded == string);
        }
    }
}

TEST_CASE("decode(encode('aaaa'))")
{
    const std::string string = "aaaa";

    for (unsigned max_distance = 1; max_distance != 10; ++max_distance)
    {
        for (unsigned max_length = 1; max_length != 10; ++max_length)
        {
            auto triplets = encode(max_distance, max_length, string);
            auto decoded = decode(triplets);

            CHECK(decoded == string);
        }
    }
}

TEST_CASE("decode(encode('aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'))")
{
    const std::string string = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    for (unsigned max_distance = 1; max_distance != 10; ++max_distance)
    {
        for (unsigned max_length = 1; max_length != 10; ++max_length)
        {
            auto triplets = encode(max_distance, max_length, string);
            auto decoded = decode(triplets);

            CHECK(decoded == string);
        }
    }
}

TEST_CASE("decode(encode('abababababababababababababababababc'))")
{
    const std::string string = "abababababababababababababababababc";

    for (unsigned max_distance = 1; max_distance != 10; ++max_distance)
    {
        for (unsigned max_length = 1; max_length != 10; ++max_length)
        {
            auto triplets = encode(max_distance, max_length, string);
            auto decoded = decode(triplets);

            CHECK(decoded == string);
        }
    }
}

#endif
