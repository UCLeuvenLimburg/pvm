#include "dead-code-elimination.h"
#include <iostream>


namespace
{
    unsigned long_computation(unsigned x)
    {
        unsigned result = 0;

        while (x != 0)
        {
            result ^= x;
            --x;
        }

        return result;
    }
}


void test_dead_code_elimination()
{
    long_computation(999999);
}