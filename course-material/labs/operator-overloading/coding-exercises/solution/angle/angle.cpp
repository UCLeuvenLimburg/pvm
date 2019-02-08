#include "angle.h"

Angle& Angle::operator=(const Angle& angle)
{
	this->_radians = angle._radians;

	return *this;
}

Angle operator+(const Angle& x, const Angle& y)
{
	return Angle::from_radians(x.radians() + y.radians());
}

Angle operator-(const Angle& x)
{
	return Angle::from_radians(-x.radians());
}

Angle operator-(const Angle& x, const Angle& y)
{
	return Angle::from_radians(x.radians() - y.radians());
}

Angle operator *(const Angle& angle, double factor)
{
	return Angle::from_radians(angle.radians() * factor);
}

Angle operator *(double factor, const Angle& angle)
{
	return angle * factor;
}

Angle operator /(const Angle& angle, double factor)
{
	return Angle::from_radians(angle.radians() / factor);
}

double operator /(const Angle& a, const Angle& b)
{
	return a.radians() / b.radians();
}

Angle& operator +=(Angle& x, const Angle& y)
{
	return (x = x + y);
}

Angle& operator -=(Angle& x, const Angle& y)
{
	return (x = x - y);
}

Angle& operator *=(Angle& x, double f)
{
	return (x = x * f);
}

Angle& operator /=(Angle& x, double f)
{
	return (x = x / f);
}

Angle operator "" _rad(long double x)
{
	return Angle::from_radians(x);
}

Angle operator "" _degrees(long double x)
{
	return Angle::from_degrees(x);
}

Angle operator "" _rad(long long unsigned x)
{
	return Angle::from_radians((long double)x);
}

Angle operator "" _degrees(long long unsigned x)
{
	return Angle::from_degrees((long double)x);
}

bool operator <(const Angle& a, const Angle& b)
{
	return a.radians() < b.radians();
}

bool operator >(const Angle& a, const Angle& b)
{
	return a.radians() > b.radians();
}

bool operator <=(const Angle& a, const Angle& b)
{
	return a.radians() <= b.radians();
}

bool operator >=(const Angle& a, const Angle& b)
{
	return a.radians() >= b.radians();
}

bool operator ==(const Angle& a, const Angle& b)
{
	return a.radians() == b.radians();
}

bool operator !=(const Angle& a, const Angle& b)
{
	return a.radians() != b.radians();
}

std::ostream& operator <<(std::ostream& out, const Angle& angle)
{
	return out << angle.degrees() << " degrees";
}
