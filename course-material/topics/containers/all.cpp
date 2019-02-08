#include <algorithm>


bool is_prime(int x) { ... }
std::vector<int> vec;

// Are all elements primes?
if (std::all_of(vec.begin(),
                vec.end(),
                is_prime))
{
    ...
}
