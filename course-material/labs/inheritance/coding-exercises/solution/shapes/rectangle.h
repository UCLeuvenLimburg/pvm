#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"


class Rectangle : public Shape
{
private:
    double _width, _height;

public:
    Rectangle(double, double);

    virtual double circumference() const override;
    virtual double area() const override;
};

#endif

