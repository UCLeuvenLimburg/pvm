#include "rewrite.h"


// Kabouter Swap's solution to avoid name clash with other exercise
void swapperdeswapperdeswap(int* p, int* q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void quotrest(int x, int y, int* q, int *r)
{
	*q = x / y;
	*r = x % y;
}

int* min(int* p, int* q, int* r)
{
	int a = *p, b = *q, c = *r;

	if (a <= b && b <= c)
	{
		return p;
	}
	else if (b <= a && b <= c)
	{
		return q;
	}
	else
	{
		return r;
	}
}

int* max(int* p, int* q, int* r)
{
	int a = *p, b = *q, c = *r;

	if (a >= b && a >= c)
	{
		return p;
	}
	else if (b >= a && b >= c)
	{
		return q;
	}
	else
	{
		return r;
	}
}

void minmax(int* p, int *q, int *r, int** minimum, int** maximum)
{
	*minimum = min(p, q, r);
	*maximum = max(p, q, r);
}

void swap_min_and_max(int* p, int* q, int* r)
{
	int* minimum;
	int* maximum;

	minmax(p, q, r, &minimum, &maximum);
	swapperdeswapperdeswap(minimum, maximum);
}

bool is_palindrome(std::vector<int> ns)
{
	for (unsigned i = 0; i < ns.size() / 2; ++i)
	{
		if (ns[i] != ns[ns.size() - i - 1])
		{
			return false;
		}
	}

	return true;
}

std::vector<int> crop(std::vector<int> ns, unsigned n)
{
	if (ns.size() < n * 2)
	{
		return std::vector<int>();
	}
	else
	{
		return std::vector<int>(ns.begin() + n, ns.end() - n);
	}
}

void rotate(std::vector<int>* ns, int delta)
{
	if ((*ns).size() > 0)
	{
		std::vector<int> temp((*ns).size());

		while (delta < 0) delta += int((*ns).size());

		for (int i = 0; i != (*ns).size(); ++i)
		{
			int j = (i + delta) % (*ns).size();

			temp[j] = (*ns)[i];
		}

		*ns = temp;
	}
}

void trim(std::string* str)
{
	auto left = std::find_if_not((*str).begin(), (*str).end(), isspace);

	if (left != (*str).end())
	{
		(*str).erase((*str).begin(), left);
	}

	auto right = std::find_if_not((*str).rbegin(), (*str).rend(), isspace);

	if (right != (*str).rend())
	{
		(*str).erase(right.base(), (*str).end());
	}
}

void uniq(std::vector<int>* ns)
{
	std::set<int> set((*ns).begin(), (*ns).end());
	*ns = std::vector<int>(set.begin(), set.end());
}