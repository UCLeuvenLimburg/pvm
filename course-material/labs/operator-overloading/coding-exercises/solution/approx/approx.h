#ifndef APPROX_H
#define APPROX_H

class approx
{
	double x, epsilon;

public:
	approx(double x, double epsilon = 0.00001)
		: x(x), epsilon(epsilon) { }

	friend bool operator ==(const approx& approx, double x);
};

bool operator ==(double x, const approx& approx);
bool operator !=(double x, const approx& approx);
bool operator !=(const approx& approx, double x);

#endif
