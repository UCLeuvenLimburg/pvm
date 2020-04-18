#define CATCH_CONFIG_MAIN
#include "string-operations.h"
#include "catch.h"
#include <memory>
#include <string>


// --------------------------------------------------------
//
// --> Comment out these definitions to turn off tests <--
//
// --------------------------------------------------------

#define TEST_LENGTH
#define TEST_OVERWRITE
#define TEST_CONCATENATE
#define TEST_REVERSE
#define TEST_PARSE




#define STR(s)       nonconst_copy(s)
#define ISTR(s)      STR(s).get()

std::unique_ptr<char> nonconst_copy(const char* str)
{
    const auto length = strlen(str);
    auto result = std::unique_ptr<char>(new char[length + 1]);

    strncpy_s(result.get(), length + 1, str, length);

    return result;
}


#ifdef TEST_LENGTH

TEST_CASE("Length of \"\"")
{
    CHECK(length(ISTR("")) == 0);
}

TEST_CASE("Length of \"a\"")
{
    CHECK(length(ISTR("a")) == 1);
}

TEST_CASE("Length of \"abc\"")
{
    CHECK(length(ISTR("abc")) == 3);
}

TEST_CASE("Length of \"12345678\"")
{
    CHECK(length(ISTR("12345678")) == 8);
}

#endif

#ifdef TEST_OVERWRITE

TEST_CASE("Overwrite with \"\"")
{
    char destination[100];
    overwrite(destination, ISTR(""));

    CHECK(std::string(destination) == "");
}

TEST_CASE("Overwrite with \"abc\"")
{
    char destination[100];
    overwrite(destination, ISTR("abc"));

    CHECK(std::string(destination) == "abc");
}

TEST_CASE("Overwrite with \"123456789\"")
{
    char destination[100];
    overwrite(destination, ISTR("123456789"));

    CHECK(std::string(destination) == "123456789");
}

#endif

#ifdef TEST_CONCATENATE

TEST_CASE("concatenate(\"\", \"\")")
{
    auto s1 = STR("");
    auto s2 = STR("");
    auto actual = concatenate(s1.get(), s2.get());

    CHECK(std::string(actual) == "");
}

TEST_CASE("concatenate(\"a\", \"\")")
{
    auto s1 = STR("a");
    auto s2 = STR("");
    auto actual = concatenate(s1.get(), s2.get());

    CHECK(std::string(actual) == "a");
}

TEST_CASE("concatenate(\"\", \"a\")")
{
    auto s1 = STR("");
    auto s2 = STR("a");
    auto actual = concatenate(s1.get(), s2.get());

    CHECK(std::string(actual) == "a");
}

TEST_CASE("concatenate(\"a\", \"b\")")
{
    auto s1 = STR("a");
    auto s2 = STR("b");
    auto actual = concatenate(s1.get(), s2.get());

    CHECK(std::string(actual) == "ab");
}

TEST_CASE("concatenate(\"abc\", \"xyz\")")
{
    auto s1 = STR("abc");
    auto s2 = STR("xyz");
    auto actual = concatenate(s1.get(), s2.get());

    CHECK(std::string(actual) == "abcxyz");
}

TEST_CASE("concatenate(\"abcde\", \"xyz\")")
{
    auto s1 = STR("abcde");
    auto s2 = STR("xyz");
    auto actual = concatenate(s1.get(), s2.get());

    CHECK(std::string(actual) == "abcdexyz");
}

#endif

#ifdef TEST_REVERSE

TEST_CASE("reverse(\"\")")
{
    auto str = STR("");
    reverse(str.get());
    CHECK(std::string(str.get()) == "");
}

TEST_CASE("reverse(\"a\")")
{
    auto str = STR("a");
    reverse(str.get());
    CHECK(std::string(str.get()) == "a");
}

TEST_CASE("reverse(\"ab\")")
{
    auto str = STR("ab");
    reverse(str.get());
    CHECK(std::string(str.get()) == "ba");
}

TEST_CASE("reverse(\"abc\")")
{
    auto str = STR("abc");
    reverse(str.get());
    CHECK(std::string(str.get()) == "cba");
}

TEST_CASE("reverse(\"123456\")")
{
    auto str = STR("123456");
    reverse(str.get());
    CHECK(std::string(str.get()) == "654321");
}

TEST_CASE("reverse(\"1234567\")")
{
    auto str = STR("1234567");
    reverse(str.get());
    CHECK(std::string(str.get()) == "7654321");
}

#endif

#ifdef TEST_PARSE

TEST_CASE("parse(\"0\")")
{
    CHECK(parse(ISTR("0")) == 0);
}

TEST_CASE("parse(\"1\")")
{
    CHECK(parse(ISTR("1")) == 1);
}

TEST_CASE("parse(\"10\")")
{
    CHECK(parse(ISTR("10")) == 10);
}

TEST_CASE("parse(\"251\")")
{
    CHECK(parse(ISTR("251")) == 251);
}

TEST_CASE("parse(\"123456798\")")
{
    CHECK(parse(ISTR("123456798")) == 123456798);
}

#endif
