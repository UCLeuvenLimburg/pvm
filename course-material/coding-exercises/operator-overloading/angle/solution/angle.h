#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>


class angle
{
private:
    double rad;

    angle(double rad);

public:
    double in_degrees() const;
    double in_radians() const;

    static angle from_degrees(double);
    static angle from_radians(double);
};

angle operator""_rad(long double);
angle operator""_deg(long double);

angle operator+(const angle&, const angle&);
angle operator-(const angle&, const angle&);
angle operator*(const angle&, double);
angle operator*(double, const angle&);
angle operator/(const angle&, double);

bool operator ==(const angle&, const angle&);
bool operator !=(const angle&, const angle&);
bool operator <(const angle&, const angle&);
bool operator <=(const angle&, const angle&);
bool operator >=(const angle&, const angle&);
bool operator >(const angle&, const angle&);

std::ostream& operator <<(std::ostream&, const angle&);

#endif
