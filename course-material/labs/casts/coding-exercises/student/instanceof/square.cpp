#include "square.h"


Square::Square(double side)
    : m_side(side) { }

double Square::area() const
{
    return m_side * m_side;
}

Circle::Circle(double radius) : m_radius(radius) { }

double Circle::area() const
{
    return 3.141592 * m_radius * m_radius;
}
