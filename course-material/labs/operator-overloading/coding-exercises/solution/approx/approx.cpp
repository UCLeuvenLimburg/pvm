#include "approx.h"
#include <cmath>


bool operator ==(const approx& approx, double x)
{
	return fabs(long double(approx.x - x)) < approx.epsilon;
}

bool operator ==(double x, const approx& approx)
{
	return approx == x;
}

bool operator !=(const approx& approx, double x)
{
	return !(approx == x);
}

bool operator !=(double x, const approx& approx)
{
	return approx != x;
}
