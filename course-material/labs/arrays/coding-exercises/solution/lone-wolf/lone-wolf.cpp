#include "lone-wolf.h"


int lone_wolf(int* ns, unsigned size)
{
    int result = 0;

    while ( size-- )
    {
        result ^= ns[size];
    }

    return result;
}