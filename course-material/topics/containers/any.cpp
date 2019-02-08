#include <algorithm>


bool is_prime(int x) { ... }
std::vector<int> vec;

// Is there a prime?
if (std::any_of(vec.begin(),
                vec.end(),
                is_prime))
{
    ...
}
