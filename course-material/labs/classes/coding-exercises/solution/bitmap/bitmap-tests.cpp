#include "bitmap.h"
#include "../Catch.h"

TEST_CASE("Bitmap width")
{
    Bitmap bitmap(10, 20);

    REQUIRE(bitmap.width() == 10);
}

TEST_CASE("Bitmap height")
{
    Bitmap bitmap(10, 20);

    REQUIRE(bitmap.height() == 20);
}

TEST_CASE("Bitmap width on const Bitmap")
{
    const Bitmap bitmap(10, 20);

    REQUIRE(bitmap.width() == 10);
}

TEST_CASE("Bitmap height on const Bitmap")
{
    Bitmap bitmap(10, 20);

    REQUIRE(bitmap.height() == 20);
}

TEST_CASE("Setting color")
{
    Bitmap bitmap(10, 10);

    bitmap.at(0, 0) = Color(1, 2, 3);

    CHECK(bitmap.at(0, 0).r == 1);
    CHECK(bitmap.at(0, 0).g == 2);
    CHECK(bitmap.at(0, 0).b == 3);
}

TEST_CASE("Reading color from const Bitmap")
{
    Bitmap bitmap(10, 10);
    const Bitmap& const_bitmap = bitmap;

    bitmap.at(0, 0) = Color(1, 2, 3);

    CHECK(const_bitmap.at(0, 0).r == 1);
    CHECK(const_bitmap.at(0, 0).g == 2);
    CHECK(const_bitmap.at(0, 0).b == 3);
}

TEST_CASE("Clearing bitmap")
{
    const double r = 0.54;
    const double g = 0.7;
    const double b = 0.15;

    Bitmap bitmap(10, 10);
    bitmap.clear(Color(r, g, b));

    for (unsigned y = 0; y != bitmap.height(); ++y)
    {
        for (unsigned x = 0; x != bitmap.width(); ++x)
        {
            CHECK(bitmap.at(x, y).r == r);
            CHECK(bitmap.at(x, y).g == g);
            CHECK(bitmap.at(x, y).b == b);
        }
    }
}