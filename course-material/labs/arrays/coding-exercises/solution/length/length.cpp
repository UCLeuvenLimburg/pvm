#include "length.h"


unsigned length(int* start, int* end)
{
    unsigned length = 0;

    while (&start[length] != end)
    {
        ++length;
    }

    return length;
}
