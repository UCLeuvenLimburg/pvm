#define _USE_MATH_DEFINES
#include "angle.h"
#include <cmath>


angle::angle(double rad)
    : rad(rad)
{
    // NOP
}

angle angle::from_radians(double size)
{
    return angle(size);
}

angle angle::from_degrees(double size)
{
    return angle(size / 180 * M_PI);
}

angle operator""_rad(long double size)
{
    return angle::from_radians(double(size));
}

angle operator""_deg(long double size)
{
    return angle::from_degrees(double(size));
}

double angle::in_degrees() const
{
    return rad * 180 / M_PI;
}

double angle::in_radians() const
{
    return rad;
}

angle operator+(const angle& a, const angle& b)
{
    return angle::from_radians(a.in_radians() + b.in_radians());
}

angle operator-(const angle& a, const angle& b)
{
    return angle::from_radians(a.in_radians() - b.in_radians());
}

angle operator*(const angle& a, double factor)
{
    return angle::from_radians(a.in_radians() * factor);
}

angle operator*(double factor, const angle& a)
{
    return a * factor;
}

angle operator/(const angle& a, double divisor)
{
    return a * (1.0 / divisor);
}

bool operator ==(const angle& a, const angle& b)
{
    return a.in_radians() == b.in_radians();
}

bool operator !=(const angle& a, const angle& b)
{
    return !(a == b);
}

bool operator <=(const angle& a, const angle& b)
{
    return a.in_radians() <= b.in_radians();
}

bool operator <(const angle& a, const angle& b)
{
    return a.in_radians() < b.in_radians();
}

bool operator >=(const angle& a, const angle& b)
{
    return a.in_radians() >= b.in_radians();
}

bool operator >(const angle& a, const angle& b)
{
    return a.in_radians() > b.in_radians();
}

std::ostream& operator <<(std::ostream& out, const angle& a)
{
    return out << a.in_degrees() << " degrees";
}
