#include "inlining.h"
#include <iostream>


namespace
{
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
}

void test_inlining()
{
    int x = 1, y = 2;
    int answer;

    std::cout << "Number of swaps: ";
    std::cin >> answer;

    for ( int i = 0; i != answer; ++i)
        swap(x, y);

    std::cout << x << y << std::endl;
}