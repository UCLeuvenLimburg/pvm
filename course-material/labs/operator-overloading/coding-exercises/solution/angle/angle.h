#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>


class Angle
{
private:
	double _radians;

	Angle(double radians) : _radians(radians) { }

public:
	static Angle from_degrees(double degrees)
	{
		return Angle(degrees / 180 * 3.141592);
	}

	static Angle from_radians(double radians)
	{
		return Angle(radians);
	}

	double radians() const { return _radians; }
	double degrees() const { return _radians / 3.141592 * 180;  }

	Angle& operator =(const Angle&);
};

Angle operator"" _rad(long double x);
Angle operator"" _degrees(long double x);
Angle operator"" _rad(long long unsigned x);
Angle operator"" _degrees(long long unsigned x);

Angle operator+(const Angle& x, const Angle& y);
Angle operator-(const Angle& x);
Angle operator-(const Angle& x, const Angle& y);
Angle operator *(const Angle& angle, double factor);
Angle operator *(double factor, const Angle& angle);
Angle operator /(const Angle& angle, double factor);
double operator /(const Angle& angle1, const Angle& angle2);

Angle& operator +=(Angle& x, const Angle& y);
Angle& operator -=(Angle& x, const Angle& y);
Angle& operator *=(Angle& x, double f);
Angle& operator /=(Angle& x, double f);

bool operator <(const Angle& a, const Angle& b);
bool operator >(const Angle& a, const Angle& b);
bool operator <=(const Angle& a, const Angle& b);
bool operator >=(const Angle& a, const Angle& b);
bool operator ==(const Angle& a, const Angle& b);
bool operator !=(const Angle& a, const Angle& b);

std::ostream& operator <<(std::ostream& out, const Angle&);

#endif
