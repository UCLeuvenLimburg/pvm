#include "train.h"
#include "../Catch.h"


void check(const Train& train, const std::vector<int>& expected_capacities, const std::vector<int>& expected_occupancies)
{
	REQUIRE(train.count_wagons() == expected_capacities.size());
	REQUIRE(train.count_wagons() == expected_occupancies.size());

	for (int i = 0; i != expected_capacities.size(); ++i)
	{
		INFO("Checking wagon with index " << i);

		auto wagon = train.nth_wagon(i);
		int actual_capacity = wagon->passenger_capacity;
		int actual_occupancy = wagon->passenger_count;
		
		CHECK(actual_capacity == expected_capacities[i]);
		CHECK(actual_occupancy == expected_occupancies[i]);
	}
}

TEST_CASE("Train creation")
{
	const Train train;

	CHECK(train.count_wagons() == 0);
}

TEST_CASE("Add wagon increments wagon count")
{
	Train train;

	train.add_wagon(10);
	CHECK(train.count_wagons() == 1);	

	train.add_wagon(10);
	CHECK(train.count_wagons() == 2);
}

TEST_CASE("Last wagon returns nullptr for empty train")
{
	Train train;

	CHECK(train.last_wagon() == nullptr);
}

TEST_CASE("Last wagon with one wagon")
{
	Train train;
	train.add_wagon(10);

	CHECK(train.last_wagon()->passenger_capacity == 10);
	CHECK(train.last_wagon()->passenger_count == 0);
}

TEST_CASE("Last wagon with two wagons")
{
	Train train;
	train.add_wagon(10);
	train.add_wagon(20);

	CHECK(train.last_wagon()->passenger_capacity == 20);
	CHECK(train.last_wagon()->passenger_count == 0);
}

TEST_CASE("0th wagon gives nullptr on empty train")
{
	Train train;

	CHECK(train.nth_wagon(0) == nullptr);
}

TEST_CASE("10th wagon gives nullptr on train of size 2")
{
	Train train;
	train.add_wagon(10);
	train.add_wagon(10);

	CHECK(train.nth_wagon(10) == nullptr);
}

TEST_CASE("nth_wagon")
{
	Train train;
	train.add_wagon(10);
	train.add_wagon(20);
	train.add_wagon(30);

	std::vector<int> expected_occupancies{ 0,0,0 };
	std::vector<int> expected_capacities{ 10,20,30 };

	check(train, expected_capacities, expected_occupancies);
}

TEST_CASE("board_passengers")
{
	Train train;
	train.add_wagon(10);
	train.add_wagon(20);
	train.add_wagon(30);

	std::vector<int> expected_capacities{ 10,20,30 };
	check(train, expected_capacities, std::vector<int>{ 0, 0, 0 });

	CHECK(train.board_passengers(5) == 0);
	check(train, expected_capacities, std::vector<int>{ 0, 0, 5 });

	CHECK(train.board_passengers(30) == 0);
	check(train, expected_capacities, std::vector<int>{ 0, 5, 30 });

	CHECK(train.board_passengers(5) == 0);
	check(train, expected_capacities, std::vector<int>{ 0, 10, 30 });

	CHECK(train.board_passengers(15) == 0);
	check(train, expected_capacities, std::vector<int>{ 5, 20, 30 });

	CHECK(train.board_passengers(10) == 5);
	check(train, expected_capacities, std::vector<int>{ 10, 20, 30 });
}
