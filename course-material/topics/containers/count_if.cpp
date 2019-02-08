#include <algorithm>


bool is_prime(int x) { ... }
std::vector<int> vec;

// Count number of primes
int n = std::count_if(vec.begin(),
                      vec.end(),
                      is_prime);

