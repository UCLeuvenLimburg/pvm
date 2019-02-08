#include "counter.h"


void Counter::reset()
{
    _value = 0;
}

void Counter::increment()
{
    increment(_step);
}

void Counter::increment(int step)
{
    _value += step;
}

int Counter::value() const
{
    return _value;
}

int Counter::step() const
{
    return _step;
}
