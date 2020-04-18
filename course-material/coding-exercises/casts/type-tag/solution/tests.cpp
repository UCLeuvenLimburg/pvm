#include "tag.h"
#include "catch.h"


TEST_CASE("Recognizing Square")
{
    Square shape;

    REQUIRE(get_tag(shape) == tag::square);
}

TEST_CASE("Recognizing Rectangle")
{
    Rectangle shape;

    REQUIRE(get_tag(shape) == tag::rectangle);
}

TEST_CASE("Recognizing Circle")
{
    Circle shape;

    REQUIRE(get_tag(shape) == tag::circle);
}

TEST_CASE("Recognizing Ellipse")
{
    Ellipse shape;

    REQUIRE(get_tag(shape) == tag::ellipse);
}

TEST_CASE("Switch")
{
    Square shape;

    switch (get_tag(shape))
    {
    case tag::circle:
        FAIL();
    case tag::ellipse:
        FAIL();
    case tag::rectangle:
        FAIL();        
    }
}