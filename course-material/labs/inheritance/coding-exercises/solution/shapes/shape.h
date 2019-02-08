#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual ~Shape() { }

    virtual double circumference() const = 0;
    virtual double area() const = 0;
};

#endif
