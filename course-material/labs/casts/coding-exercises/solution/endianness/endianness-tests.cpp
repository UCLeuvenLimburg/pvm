#include "endianness.h"
#include "../Catch.h"


TEST_CASE("endianness")
{
    CHECK(is_little_endian());
    CHECK(!is_big_endian());
}
