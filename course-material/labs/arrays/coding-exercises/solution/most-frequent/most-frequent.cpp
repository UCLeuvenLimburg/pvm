#include "most-frequent.h"
#include <limits>


int minimum(int* ns, unsigned size)
{
    int result = std::numeric_limits<int>::max();
    
    for (unsigned i = 0; i != size; ++i)
    {
        result = ns[i] < result ? ns[i] : result;
    }

    return result;
}


int maximum(int* ns, unsigned size)
{
    int result = std::numeric_limits<int>::min();

    for (unsigned i = 0; i != size; ++i)
    {
        result = ns[i] > result ? ns[i] : result;
    }

    return result;
}


int most_frequent(int* ns, unsigned size)
{
    int min = minimum(ns, size);
    int max = maximum(ns, size);
    unsigned range = unsigned(max - min + 1);
    unsigned* frequencies = new unsigned[range];

    for (unsigned i = 0; i != range; ++i)
    {
        frequencies[i] = 0;
    }
    
    for (unsigned i = 0; i != size; ++i)
    {        
        frequencies[ns[i] - min]++;
    }

    unsigned best_index = 0;

    for (unsigned i = 1; i < range; ++i)
    {
        if (frequencies[i] > frequencies[best_index])
        {
            best_index = i;
        }
    }

    delete[] frequencies;

    return best_index + min;
}
