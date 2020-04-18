#include "count-bits.h"


unsigned count_bits(uint64_t n)
{
    unsigned count = 0;

    while (n != 0)
    {
        count += (n & 1);
        n >>= 1;
    }

    return count;
}
