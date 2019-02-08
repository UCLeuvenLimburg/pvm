#include "actor.h"
#include "Catch.h"


TEST_CASE("Constructor")
{
    Actor actor("John Malkovich", Date(9, 12, 1953));

    REQUIRE(actor.name() == "John Malkovich");
    REQUIRE(actor.birthday() == Date(9, 12, 1953));
}