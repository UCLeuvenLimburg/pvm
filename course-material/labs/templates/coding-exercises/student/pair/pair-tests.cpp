// Double include done on purpose
#include "pair.h"
#include "pair.h"
#include "../Catch.h"


TEST_CASE("Creating pair using default constructor")
{
    Pair<int, bool>();
}

TEST_CASE("Creating pair using binary constructor")
{
    Pair<int, bool> pair(5, true);

    CHECK(pair.first == 5);
    CHECK(pair.second == true);
}