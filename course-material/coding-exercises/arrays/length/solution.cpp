#include "solution.h"


unsigned length(int* start, int* end)
{
    // Using pointer arithmetic: subtracting pointers T* returns the number of T's that fit in between them
    return end - start;
}

unsigned length2(int* start, int* end)
{
    unsigned i = 0;

    // Find element whose address equals end
    while (&start[i] != end)
    {
        ++i;
    }

    return i;
}
