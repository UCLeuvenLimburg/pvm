#ifndef REVERSE_H
#define REVERSE_H

template<typename Iterator>
void reverse(Iterator start, Iterator end)
{
    while (start != end)
    {
        end--;

        if (start == end)
        {
            return;
        }

        auto temp = *start;
        *start = *end;
        *end = temp;

        ++start;
    }
}

#endif
