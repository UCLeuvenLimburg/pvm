#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    double r, g, b;

    Color();
    Color(double, double, double);

    static Color black() { return Color(0, 0, 0); }
    static Color white() { return Color(1, 1, 1); }
    static Color red() { return Color(1, 0, 0); }
    static Color green() { return Color(0, 1, 0); }
    static Color blue() { return Color(0, 0, 1); }

    void clamp();
    void multiply(double);
};

#endif
