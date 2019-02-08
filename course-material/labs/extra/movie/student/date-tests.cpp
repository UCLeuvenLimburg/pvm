#include "date.h"
#include "Catch.h"
#include <sstream>


TEST_CASE("Date constructor")
{
    Date date(1, 2, 3);

    CHECK(date.day == 1);
    CHECK(date.month == 2);
    CHECK(date.year == 3);
}

TEST_CASE("Date Equality")
{
    Date d1(1, 2, 3);
    Date d2(1, 2, 3);
    Date d3(5, 2, 3);
    Date d4(1, 5, 3);
    Date d5(1, 2, 5);

    CHECK(d1 == d2);
    CHECK(d2 == d1);
    CHECK(!(d1 == d3));
    CHECK(!(d1 == d4));
    CHECK(!(d1 == d5));
}

TEST_CASE("Date Inequality")
{
    Date d1(1, 2, 3);
    Date d2(1, 2, 3);
    Date d3(5, 2, 3);
    Date d4(1, 5, 3);
    Date d5(1, 2, 5);

    CHECK(!(d1 != d2));
    CHECK(!(d2 != d1));
    CHECK(d1 != d3);
    CHECK(d1 != d4);
    CHECK(d1 != d5);
}

TEST_CASE("Date outputting")
{
    std::stringstream ss;
    ss << Date(18, 12, 1980);

    CHECK(ss.str() == "18/12/1980");
}
