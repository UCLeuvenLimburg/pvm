#include "rewrite.h"
#include "../Catch.h"
#include <functional>


TEST_CASE("swap's Type")
{
	std::function<void(int&, int&)> _ = swapperdeswapperdeswap;
}

TEST_CASE("quotrest's Type")
{
	std::function<void(int, int, int&, int&)> _ = quotrest;
}

TEST_CASE("min's Type")
{
	std::function<int& (int&, int&, int&)> _ = min;
}

TEST_CASE("max's Type")
{
	std::function<int& (int&, int&, int&)> _ = max;
}

TEST_CASE("minmax's Type")
{
	std::function<void(int&, int&, int&, int*&, int*&)> _ = minmax;
}

TEST_CASE("swap_min_and_max's Type")
{
	std::function<void(int&, int&, int&)> _ = swap_min_and_max;
}

TEST_CASE("swap_min_and_max(1, 2, 3)")
{
	int a = 1, b = 2, c = 3;

	swap_min_and_max(a, b, c);

	REQUIRE(a == 3);
	REQUIRE(b == 2);
	REQUIRE(c == 1);
}

TEST_CASE("is_palindrome's Type")
{
	std::function<bool(const std::vector<int>&)> _ = is_palindrome;
}

TEST_CASE("crop's Type")
{
	std::function<std::vector<int>(const std::vector<int>&, unsigned)> _ = crop;
}

TEST_CASE("rotate's Type")
{
	std::function<void(std::vector<int>&, int)> _ = rotate;
}

TEST_CASE("trim's Type")
{
	std::function<void(std::string&)> _ = trim;
}

TEST_CASE("uniq's Type")
{
	std::function<void(std::vector<int>&)> _ = uniq;
}
