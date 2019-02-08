#include "counter.h"


Counter::Counter()
    : Counter(0) { }

Counter::Counter(unsigned value) : value(value) { }

unsigned Counter::getValue() const
{
    return this->value;
}

void Counter::setValue(unsigned value)
{
    this->value = value;
}

void Counter::increment()
{
    ++value;
}

void Counter::reset()
{
    value = 0;
}
