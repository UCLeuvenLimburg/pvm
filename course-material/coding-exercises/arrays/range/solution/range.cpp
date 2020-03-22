#include "range.h"

int* range(int from, int to)
{
    int width = to - from + 1;
    int* result = new int[width];

    for (int i = 0; i != width; ++i)
    {
        result[i] = from + i;
    }

    return result;
}
