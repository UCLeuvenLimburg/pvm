#include "compile-time-execution.h"
#include <iostream>


namespace
{
    int sum(int from, int to)
    {
        int result = 0;

        for (int i = from; i <= to; ++i)
        {
            result += i;
        }

        return result;
    }
}

void test_compile_time_execution()
{
    std::cout << sum(0, 5) << std::endl;
}
