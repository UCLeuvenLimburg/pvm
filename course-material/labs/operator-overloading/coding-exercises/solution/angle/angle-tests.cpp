#include "angle.h"
#include "../Catch.h"
#include <sstream>


TEST_CASE("Angle creation with from_radians")
{
	const Angle angle = Angle::from_radians(2);

	CHECK(angle.radians() == Approx(2.0));
	CHECK(angle.degrees() == Approx(2.0 * 180.0 / 3.141592));
}

TEST_CASE("Angle creation with from_degrees")
{
	const Angle angle = Angle::from_degrees(180);

	CHECK(angle.radians() == Approx(3.141592));
	CHECK(angle.degrees() == Approx(180));
}

TEST_CASE("Angle creation using int_rad literal")
{
	const Angle angle = 5_rad;

	CHECK(angle.radians() == Approx(5));
}

TEST_CASE("Angle creation using int_degrees literal")
{
	const Angle angle = 45_degrees;

	CHECK(angle.degrees() == Approx(45));
}

TEST_CASE("Angle creation using double_rad literal")
{
	const Angle angle = 5.2_rad;

	CHECK(angle.radians() == Approx(5.2));
}

TEST_CASE("Angle creation using double_degrees literal")
{
	const Angle angle = 45.8_degrees;

	CHECK(angle.degrees() == Approx(45.8));
}

TEST_CASE("Angle = Angle")
{
	Angle x = 50_degrees;
	const Angle y = 30_degrees;

	x = y;

	CHECK(x.degrees() == Approx(30));
	CHECK(y.degrees() == Approx(30));
}

TEST_CASE("Angle + Angle")
{
	const Angle x = 25_degrees;
	const Angle y = 77_degrees;
	const Angle z = x + y;

	CHECK(z.degrees() == Approx(25 + 77));
}

TEST_CASE("-Angle")
{
	const Angle x = 62_degrees;
	const Angle y = -x;

	CHECK(y.degrees() == Approx(-62));
}

TEST_CASE("Angle - Angle")
{
	const Angle x = 25_degrees;
	const Angle y = 77_degrees;
	const Angle z = x - y;

	CHECK(z.degrees() == Approx(25 - 77));
}

TEST_CASE("Angle * double")
{
	const Angle x = 64_degrees;
	const Angle y = x * 5;

	CHECK(y.degrees() == Approx(64 * 5));
}

TEST_CASE("double * Angle")
{
	const Angle x = 72_degrees;
	const Angle y = 2 * x;

	CHECK(y.degrees() == Approx(72 * 2));
}

TEST_CASE("Angle / double")
{
	const Angle x = 72_degrees;
	const Angle y = x / 3;

	CHECK(y.degrees() == Approx(72 / 3));
}

TEST_CASE("Angle / Angle")
{
	const Angle x = 72_degrees;
	const Angle y = 35_degrees;
	double z = x / y;

	CHECK(z == Approx(72.0 / 35.0));
}

TEST_CASE("Angle += Angle")
{
	Angle x = 41_degrees;
	const Angle y = 16_degrees;
	x += y;

	CHECK(x.degrees() == Approx(41 + 16));
}

TEST_CASE("Angle -= Angle")
{
	Angle x = 41_degrees;
	const Angle y = 16_degrees;
	x -= y;

	CHECK(x.degrees() == Approx(41 - 16));
}

TEST_CASE("Angle *= double")
{
	Angle x = 41_degrees;
	x *= 3;

	CHECK(x.degrees() == Approx(41 * 3));
}

TEST_CASE("Angle /= double")
{
	Angle x = 41_degrees;
	x /= 3;

	CHECK(x.degrees() == Approx(41.0 / 3.0));
}

TEST_CASE("Comparing angles")
{
	const Angle x = 51_degrees;
	const Angle y = 61_degrees;

	CHECK(x < y);
	CHECK(!(y < x));
	CHECK(!(x < x));
	CHECK(!(y < y));

	CHECK(!(x > y));
	CHECK(y > x);
	CHECK(!(x > x));
	CHECK(!(y > y));

	CHECK(x <= y);
	CHECK(!(y <= x));
	CHECK(x <= x);
	CHECK(y <= y);

	CHECK(!(x >= y));
	CHECK(y >= x);
	CHECK(x >= x);
	CHECK(y >= y);
}

TEST_CASE("ostream << Angle")
{
	std::stringstream ss;
	const Angle x = 77_degrees;

	ss << x;

	CHECK(ss.str() == "77 degrees");
}