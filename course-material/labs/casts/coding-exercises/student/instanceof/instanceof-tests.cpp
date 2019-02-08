#include "square.h"
#include "../Catch.h"
#include <memory>


TEST_CASE("is_square on Square")
{
    std::shared_ptr<Shape> p = std::make_shared<Square>(5);

    REQUIRE(is_square(p.get()));
}

TEST_CASE("is_square on Circle")
{
    std::shared_ptr<Shape> p = std::make_shared<Circle>(5);

    REQUIRE(!is_square(p.get()));
}

TEST_CASE("is_instance_of<Circle> on Circle")
{
    std::shared_ptr<Shape> p = std::make_shared<Circle>(5);

    REQUIRE(is_instance_of<Circle>(p.get()));
}

TEST_CASE("is_instance_of<Circle> on Square")
{
    std::shared_ptr<Shape> p = std::make_shared<Square>(5);

    REQUIRE(!is_instance_of<Circle>(p.get()));
}
