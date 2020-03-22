#include "solution.h"


void veryquicksort(int* ns, unsigned size)
{
    // Allocate on the stack
    // The { } leads the elements to be initialized to zero.
    // Without it, the array would contain random values.
    unsigned frequencies[10] = { };

    for (unsigned i = 0; i != size; ++i)
    {
        frequencies[ns[i]]++;
    }

    unsigned index = 0;
    for (unsigned i = 0; i != 10; ++i)
    {
        for (unsigned j = 0; j != frequencies[i]; ++j)
        {
            ns[index++] = i;
        }
    }
}
