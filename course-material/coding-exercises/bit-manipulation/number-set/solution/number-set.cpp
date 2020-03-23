#include "number-set.h"


NumberSet::NumberSet()
    : contents(0)
{
    // NOP
}

void NumberSet::add(unsigned i)
{
    contents = contents | (1 << i);
}

void NumberSet::remove(unsigned i)
{
    contents = contents & ~(1 << i);
}

bool NumberSet::contains(unsigned i) const
{
    return (contents & (1 << i)) != 0;
}

void NumberSet::intersection(const NumberSet& other)
{
    contents = contents & other.contents;
}

void NumberSet::union_with(const NumberSet& other)
{
    contents = contents | other.contents;
}

unsigned NumberSet::size() const
{
    unsigned count = 0;

    for (unsigned i = 0; i != sizeof(uint32_t) * 8; ++i)
    {
        if (contains(i))
        {
            ++count;
        }
    }

    return count;
}
