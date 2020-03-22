#include "zero.h"

void zero(int* ns, unsigned size)
{
    // Using indexing
    for (unsigned i = 0; i != size; ++i)
    {
        ns[i] = 0;
    }
}

void zero2(int* ns, unsigned size)
{
    // Moving pointer around
    while (size != 0)
    {
        *ns = 0;
        ++ns;
        --size;
    }
}
