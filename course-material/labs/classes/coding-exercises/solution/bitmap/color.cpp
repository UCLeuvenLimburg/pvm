#include "color.h"

Color::Color()
    : Color(0,0,0) { }

Color::Color(double r, double g, double b)
    : r(r), g(g), b(b) { }

double clamp(double x)
{
    if (x < 0)
    {
        return 0;
    }
    else if (x > 1)
    {
        return 1;
    }
    else
    {
        return x;
    }
}

void Color::clamp()
{
    r = ::clamp(r);
    g = ::clamp(g);
    b = ::clamp(b);
}

void Color::multiply(double factor)
{
    r *= factor;
    g *= factor;
    b *= factor;
}
