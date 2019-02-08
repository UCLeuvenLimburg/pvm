#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include "../Catch.h"
#include <memory>


TEST_CASE("Circumference of rectangle, static binding")
{
    const Rectangle rect(3, 6);

    REQUIRE(rect.circumference() == Approx(18));
}

TEST_CASE("Area of rectangle, static binding")
{
    const Rectangle rect(4, 5);

    REQUIRE(rect.area() == Approx(20));
}

TEST_CASE("Circumference of square, static binding")
{
    const Square square(9);

    REQUIRE(square.circumference() == Approx(36));
}

TEST_CASE("Area of square, static binding")
{
    const Square square(7);

    REQUIRE(square.area() == Approx(49));
}

TEST_CASE("Circumference of rectangle, dynamic binding")
{
    std::unique_ptr<Shape> p = std::make_unique<Rectangle>(3, 9);

    REQUIRE(p->circumference() == Approx(24));
}

TEST_CASE("Area of rectangle, dynamic binding")
{
    std::unique_ptr<Shape> p = std::make_unique<Rectangle>(4, 7);

    REQUIRE(p->area() == Approx(28));
}

TEST_CASE("Circumference of square, dynamic binding")
{
    std::unique_ptr<Shape> p = std::make_unique<Square>(10);

    REQUIRE(p->circumference() == Approx(40));
}

TEST_CASE("Area of square, dynamic binding")
{
    std::unique_ptr<Shape> p = std::make_unique<Square>(10);

    REQUIRE(p->area() == Approx(100));
}

TEST_CASE("Square is subtype of Rectangle")
{
    std::unique_ptr<Rectangle> p = std::make_unique<Square>(10);
}
