#include "memory-alignment.h"
#include "shared.h"
#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>
#include <random>
#include <functional>
#include <vector>
#include <algorithm>


namespace
{
    void process(std::vector<int>& ns, const std::vector<unsigned>& indices)
    {
        for (auto i : indices)
        {
            ns[i]++;
        }
    }
}

void test_sequential_access(int size)
{
    std::vector<int> ns(size);
    auto indices = range<unsigned>(0, size);

    std::cout << "Time for sequential access: " << measure_time([&]() {process(ns, indices);}) << std::endl;

    shuffle(indices);
    std::cout << "Time for random access: " << measure_time([&]() {process(ns, indices);}) << std::endl;
}