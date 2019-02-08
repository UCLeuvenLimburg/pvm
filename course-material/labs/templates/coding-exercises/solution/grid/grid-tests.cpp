#include "grid.h"
#include "../Catch.h"


struct Dummy
{
    int value;

    Dummy() : value(5) { }
};


TEST_CASE("Grid dimensions")
{
    const Grid<int> grid(10, 15);

    CHECK(grid.width() == 10);
    CHECK(grid.height() == 15);
}

TEST_CASE("Initial grid contents")
{
    const Grid<Dummy> grid(5, 5);

    for (int y = 0; y != grid.width(); ++y)
    {
        for (int x = 0; x != grid.height(); ++x)
        {
            CHECK(grid[Position(x, y)].value == 5);
        }
    }
}

TEST_CASE("Writing to grid")
{
    Grid<int> grid(20, 20);

    grid[Position(10, 10)] = 4;

    CHECK(grid[Position(10, 10)] == 4);
}