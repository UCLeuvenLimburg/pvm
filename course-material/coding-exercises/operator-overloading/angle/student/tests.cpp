#define CATCH_CONFIG_MAIN
#define _USE_MATH_DEFINES
#include "angle.h"
#include "catch.h"
#include <cmath>
#include <sstream>


TEST_CASE("Create in radians")
{
    const auto a = 1.0_rad;

    CHECK(a.in_radians() == Approx(1.0));
}

TEST_CASE("Create in degrees")
{
    const auto a = 25.0_deg;

    CHECK(a.in_degrees() == Approx(25.0));
}

TEST_CASE("Create in degrees, read in radians")
{
    const auto a = 360.0_deg;

    CHECK(a.in_radians() == Approx(2 * M_PI));
}

TEST_CASE("Create in radians, read in degrees")
{
    const auto a = 1.0471975511965977461542144610932_rad;

    CHECK(a.in_degrees() == Approx(60));
}

TEST_CASE("Addition")
{
    const auto a = 1.0_rad;
    const auto b = 2.0_rad;

    CHECK((a + b).in_radians() == Approx(3.0));
}

TEST_CASE("Subtraction")
{
    const auto a = 5.0_rad;
    const auto b = 3.0_rad;

    CHECK((a - b).in_radians() == Approx(2.0));
}

TEST_CASE("Multiplication angle * constant")
{
    const auto a = 50.0_deg;

    CHECK((a * 2).in_degrees() == Approx(100.0));
}

TEST_CASE("Multiplication constant * angle")
{
    const auto a = 40.0_deg;

    CHECK((3 * a).in_degrees() == Approx(120.0));
}

TEST_CASE("Division")
{
    const auto a = 200.0_deg;

    CHECK((a / 5).in_degrees() == Approx(40.0));
}

TEST_CASE("Comparison")
{
    CHECK(0.0_rad == 0.0_rad);
    CHECK(10.0_rad == 10.0_rad);
    CHECK(!(0.0_rad == 10.0_rad));
    CHECK(!(5.0_rad == 7.0_rad));

    CHECK(2.0_rad != 0.0_rad);
    CHECK(7.0_rad != 10.0_rad);
    CHECK(!(1.0_rad != 1.0_rad));

    CHECK(1.0_rad < 2.0_rad);
    CHECK(!(5.0_rad < 2.0_rad));
    CHECK(!(5.0_rad < 5.0_rad));

    CHECK(1.0_rad <= 2.0_rad);
    CHECK(2.0_rad <= 2.0_rad);
    CHECK(!(2.0_rad <= 0.0_rad));

    CHECK(4.0_rad > 1.0_rad);
    CHECK(!(4.0_rad > 4.0_rad));
    CHECK(!(4.0_rad > 8.0_rad));

    CHECK(5.0_rad >= 2.0_rad);
    CHECK(5.0_rad >= 5.0_rad);
    CHECK(!(5.0_rad >= 6.0_rad));

    const auto a = 0.0_rad;
    CHECK(a == a);
    CHECK(!(a != a));
    CHECK(!(a < a));
    CHECK(!(a > a));
    CHECK(a <= a);
    CHECK(a >= a);
}

TEST_CASE("out << angle")
{
    const auto a = 60.0_deg;
    std::stringstream ss;

    ss << a;

    CHECK(ss.str() == "60 degrees");
}
