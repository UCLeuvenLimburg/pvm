#include "nth.h"
#include "../Catch.h"


TEST_CASE("nth({1, 2, 3}, 0) should return reference to 1")
{
	std::vector<int> ns{ 1,2,3 };
	int index = 0;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[index]);
	REQUIRE(&ref == &ns[index]);
}

TEST_CASE("nth({1, 2, 3}, 1) should return reference to 2")
{
	std::vector<int> ns{ 1,2,3 };
	int index = 1;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[index]);
	REQUIRE(&ref == &ns[index]);
}

TEST_CASE("nth({1, 2, 3}, 2) should return reference to 3")
{
	std::vector<int> ns{ 1,2,3 };
	int index = 2;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[index]);
	REQUIRE(&ref == &ns[index]);
}

TEST_CASE("nth({1, 2, 3}, 3) should return reference to 1")
{
	std::vector<int> ns{ 1,2,3 };
	int index = 3;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[0]);
	REQUIRE(&ref == &ns[0]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, 100) should return reference to 1")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = 100;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[0]);
	REQUIRE(&ref == &ns[0]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, 102) should return reference to 3")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = 102;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[2]);
	REQUIRE(&ref == &ns[2]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, -1) should return reference to 5")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = -1;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[4]);
	REQUIRE(&ref == &ns[4]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, -2) should return reference to 4")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = -2;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[3]);
	REQUIRE(&ref == &ns[3]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, -3) should return reference to 3")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = -3;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[2]);
	REQUIRE(&ref == &ns[2]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, -4) should return reference to 2")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = -4;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[1]);
	REQUIRE(&ref == &ns[1]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, -5) should return reference to 1")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = -5;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[0]);
	REQUIRE(&ref == &ns[0]);
}

TEST_CASE("nth({1, 2, 3, 4, 5}, -15432) should return reference to 4")
{
	std::vector<int> ns{ 1,2,3,4,5 };
	int index = -15432;

	int& ref = nth(ns, index);

	REQUIRE(ref == ns[3]);
	REQUIRE(&ref == &ns[3]);
}

TEST_CASE("nth({1, 2, 3}, 0) with const vector should return 1")
{
	const std::vector<int> ns{ 1,2,3 };
	int index = 0;

	int ref = nth(ns, index);

	REQUIRE(ref == ns[index]);
}

TEST_CASE("nth({1, 2, 3}, -1 with const vector should return 3")
{
	const std::vector<int> ns{ 1,2,3 };
	int index = -1;

	int ref = nth(ns, index);

	REQUIRE(ref == ns[2]);
}