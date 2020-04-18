#include "lone-wolf.h"

int lone_wolf(int* ns, unsigned size)
{
    for (int i = 0; i != size; ++i)
    {
        int count = 0;

        for (int j = 0; j != size; ++j)
        {
            if (ns[i] == ns[j])
            {
                ++count;
            }
        }

        if (count % 2 == 1)
        {
            return ns[i];
        }
    }

    // It is guaranteed that there is a lone wolf
    // So execution will never reach this point
    // We can omit a return here
}

int lone_wolf2(int* ns, unsigned size)
{
    int result = 0;

    for (int i = 0; i != size; ++i)
    {
        // Rely on XOR
        // Property 1: 0 ^ x = x
        // Property 2: x ^ x == 0.
        // Meaning all pairs cancel each other out, leaving the lone wolf
        result ^= ns[i];
    }

    return result;
}
