#ifndef SQUARE_H
#define SQUARE_H

class Shape
{
public:
    virtual double area() const = 0;
};


class Square : public Shape
{
    double m_side;

public:
    Square(double side);

    double area() const override;
};


class Circle : public Shape
{
    double m_radius;

public:
    Circle(double radius);

    double area() const override;

};

#endif
