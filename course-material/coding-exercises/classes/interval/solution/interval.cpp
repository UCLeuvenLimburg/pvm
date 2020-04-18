#include "interval.h"


// IMPORTANT! Use initializer lists
Interval::Interval(double lower, double upper)
    : lower(lower), upper(upper) { }


double Interval::lower_bound() const
{
    return lower;
}

double Interval::upper_bound() const
{
    return upper;
}

void Interval::set_lower_bound(double lower_bound)
{
    lower = lower_bound;
}

void Interval::set_upper_bound(double upper_bound)
{
    upper = upper_bound;
}

bool Interval::contains(double x) const
{
    return lower <= x && x <= upper;
}
