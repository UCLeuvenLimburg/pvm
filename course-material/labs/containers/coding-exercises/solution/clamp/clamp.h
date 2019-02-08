#ifndef CLAMP_H
#define CLAMP_H

#include <vector>


template<typename Iterator>
void clamp(Iterator start, Iterator end)
{
    while (start != end)
    {
        if (*start < 0)
        {
            *start = 0;
        }

        ++start;
    }
}

#endif
