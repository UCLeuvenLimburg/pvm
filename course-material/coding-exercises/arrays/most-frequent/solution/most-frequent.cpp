#include "most-frequent.h"


int most_frequent(int* ns, unsigned size)
{
    // Adding {} is a simple way to initialize all elements to zero
    // Without {} the initial values are random
    int frequencies[101]{};
    int result = 0;

    for (unsigned i = 0; i != size; ++i)
    {
        frequencies[ns[i]]++;
        
        if (frequencies[ns[i]] > frequencies[result])
        {
            result = ns[i];
        }
    }

    return result;
}
