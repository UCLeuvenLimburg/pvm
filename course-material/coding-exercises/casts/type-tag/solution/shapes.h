#ifndef SHAPES_H
#define SHAPES_H

class Shape
{
public:
    virtual ~Shape() { }
};

class Rectangle : public Shape { };
class Square: public Rectangle { };
class Ellipse : public Shape { };
class Circle : public Ellipse { };

enum class tag
{
    rectangle,
    square,
    ellipse,
    circle
};

#endif
