#include "rectangle.h"


Rectangle::Rectangle(double width, double height)
    : _width(width), _height(height)
{
    // NOP
}


double Rectangle::circumference() const
{
    return 2 * (_width + _height);
}

double Rectangle::area() const
{
    return _width * _height;
}
