#include "approx.h"
#include "../Catch.h"


TEST_CASE("Approx tests")
{
	CHECK(approx(5) == 5);
	CHECK(approx(5, 0.1) == 5.01);
	CHECK(approx(5, 0.1) == 4.99);
	CHECK(approx(7) != 8);
	CHECK(13 == approx(13));
	CHECK(13.001 == approx(13, 0.1));
	CHECK(12.999 == approx(13, 0.01));
	CHECK(15 != approx(77));
}
