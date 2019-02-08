#include "color.h"
#include "../Catch.h"

TEST_CASE("Color black")
{
    auto c = Color::black();

    CHECK(c.r == 0);
    CHECK(c.g == 0);
    CHECK(c.b == 0);
}

TEST_CASE("Color white")
{
    auto c = Color::white();

    CHECK(c.r == 1);
    CHECK(c.g == 1);
    CHECK(c.b == 1);
}

TEST_CASE("Color red")
{
    auto c = Color::red();

    CHECK(c.r == 1);
    CHECK(c.g == 0);
    CHECK(c.b == 0);
}

TEST_CASE("Color green")
{
    auto c = Color::green();

    CHECK(c.r == 0);
    CHECK(c.g == 1);
    CHECK(c.b == 0);
}

TEST_CASE("Color blue")
{
    auto c = Color::blue();

    CHECK(c.r == 0);
    CHECK(c.g == 0);
    CHECK(c.b == 1);
}

TEST_CASE("Clamping (0, 0, 0)")
{
    Color c(0, 0, 0);
    c.clamp();

    CHECK(c.r == 0);
    CHECK(c.g == 0);
    CHECK(c.b == 0);
}

TEST_CASE("Clamping (0.25, 0.5, 0.75)")
{
    Color c(0.25, 0.5, 0.75);
    c.clamp();

    CHECK(c.r == 0.25);
    CHECK(c.g == 0.5);
    CHECK(c.b == 0.75);
}

TEST_CASE("Clamping (1, 1, 1)")
{
    Color c(1, 1, 1);
    c.clamp();

    CHECK(c.r == 1);
    CHECK(c.g == 1);
    CHECK(c.b == 1);
}

TEST_CASE("Clamping (-0.1, -0.2, -0.3)")
{
    Color c(-0.1, -0.2, -0.3);
    c.clamp();

    CHECK(c.r == 0);
    CHECK(c.g == 0);
    CHECK(c.b == 0);
}

TEST_CASE("Clamping (1.1, 1.5, 5)")
{
    Color c(1.1, 1.5, 5);
    c.clamp();

    CHECK(c.r == 1);
    CHECK(c.g == 1);
    CHECK(c.b == 1);
}

TEST_CASE("Clamping (0.5, 2, -0.5)")
{
    Color c(0.5, 2, -0.5);
    c.clamp();

    CHECK(c.r == 0.5);
    CHECK(c.g == 1);
    CHECK(c.b == 0);
}

TEST_CASE("Multiplying (0, 0, 0) by 2")
{
    Color c(0, 0, 0);
    c.multiply(2);

    CHECK(c.r == 0);
    CHECK(c.g == 0);
    CHECK(c.b == 0);
}

TEST_CASE("Multiplying (1, 1, 1) by 2")
{
    Color c(1, 1, 1);
    c.multiply(2);

    CHECK(c.r == Approx(2));
    CHECK(c.g == Approx(2));
    CHECK(c.b == Approx(2));
}

TEST_CASE("Multiplying (0.5, 1, 1.5) by 0.1")
{
    Color c(0.5, 1, 1.5);
    c.multiply(0.1);

    CHECK(c.r == Approx(0.05));
    CHECK(c.g == Approx(0.1));
    CHECK(c.b == Approx(0.15));
}

