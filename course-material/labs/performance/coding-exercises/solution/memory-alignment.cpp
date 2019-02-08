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
    void process(uint64_t* p, const std::vector<unsigned>& indices)
    {
        for (auto i : indices)
        {
            p[i]++;
        }
    }

    std::vector<unsigned> random_indices(int length)
    {
        std::vector<unsigned> result = range<unsigned>(0, length);
        shuffle(result);

        return result;
    }

    void measure(char* p, const std::vector<unsigned>& indices)
    {
        std::cout << "Address = 8k+" << (reinterpret_cast<uint64_t>(p) % 8) << std::endl;
        std::cout << "Time taken: " << measure_time([&]() {process(reinterpret_cast<uint64_t*>(p), indices);}) << std::endl;
    }
}

void test_memory_alignment(int size)
{
    std::unique_ptr<uint64_t[]> data(new uint64_t[size + 8]);
    char* p = reinterpret_cast<char*>(data.get());
    std::cout << "Generating indices" << std::endl;
    auto indices = random_indices(size);

    for (int i = 0; i != 8; ++i)
    {
        measure(p + i, indices);
    }
}