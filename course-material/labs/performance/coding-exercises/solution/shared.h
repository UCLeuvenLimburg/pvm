#ifndef SHARED_H
#define SHARED_H

#include <functional>
#include <algorithm>
#include <vector>
#include <random>

long long measure_time(std::function<void()> function);

template<typename T>
long long measure_time(std::function<T()> function, T* result)
{
    return measure_time([function, result]() { *result = function(); });
}

template<typename T>
void shuffle(std::vector<T>& xs)
{
    std::shuffle(xs.begin(), xs.end(), std::default_random_engine());
}

template<typename T>
std::vector<T> create_vector(unsigned size, std::function<T(unsigned)> f)
{
    std::vector<T> result(size);

    for (unsigned i = 0; i != size; ++i)
    {
        result[i] = f(i);
    }

    return result;
}

template<typename T>
std::vector<T> range(T from, T to)
{
    return create_vector<T>(to - from, [=](unsigned i) { return from + i; });    
}

template<typename T>
std::vector<T> inverse_range(T from, T to)
{
    return create_vector<T>(to - from, [=](unsigned i) { return to - i - 1; });
}

#endif
