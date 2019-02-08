#include "veryquicksort.h"

void veryquicksort(int* ns, unsigned size)
{
    unsigned frequencies[10] = { 0,0,0,0,0,0,0,0,0,0 };

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