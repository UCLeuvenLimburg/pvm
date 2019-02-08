#include "branch-prediction.h"
#include "shared.h"
#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>
#include <random>
#include <functional>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>


namespace
{
    uint64_t process(uint64_t max, unsigned mask)
    {
        uint64_t result = 0;

        for (uint64_t i = 0; i != max; ++i)
        {
            if (i & mask)
            {
                result *= 2;
            }
            else
            {
                result++;
            }
        }

        return result;
    }

    int highest_bit(unsigned mask)
    {
        if (mask == 0)
        {
            return 0;
        }
        else
        {
            unsigned result = 0;

            while (mask)
            {
                mask = mask >> 1;
                ++result;
            }

            return 1 << result;
        }
    }

    std::string pattern(unsigned mask)
    {
        std::stringstream ss;

        unsigned imax = highest_bit(mask);
        for (unsigned i = 0; i != imax; ++i)
        {
            ss << (i & mask ? 'T' : 'F');
        }

        return ss.str();
    }

    void test(uint64_t max, unsigned mask)
    {
        uint64_t result;

        auto duration = measure_time([max, mask, &result]() {
            result = process(max, mask);
        });

        std::cout << "Masking with " << mask << " [" << pattern(mask) << "] up to " << max << " --> " << duration << "ms [" << result << "]" << std::endl;
    }
}


void test_branch_prediction(uint64_t size)
{
    test(size, 0);
    test(size, -1);

    for (unsigned i = 0; i != 16; ++i)
    {
        test(size, i);
    }
}