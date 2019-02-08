#include "complex.h"
#include <cmath>


double Complex::abs_sqr() const
{
    return re * re + im * im;
}

double Complex::abs() const
{
    return sqrt(abs_sqr());
}

Complex Complex::conjugate() const
{
    return Complex(re, -im);
}

Complex operator"" _i(long long unsigned im)
{
	return Complex(0, (double)im);
}

Complex operator"" _i(long double im)
{
	return Complex(0, (double)im);
}

Complex operator +(const Complex& a, const Complex& b)
{
    double re = a.re + b.re;
    double im = a.im + b.im;

    return Complex(re, im);
}

Complex operator -(const Complex& a)
{
    double re = -a.re;
    double im = -a.im;

    return Complex(re, im);
}

Complex operator -(const Complex& a, const Complex& b)
{
    return a + (-b);
}

Complex operator *(const Complex& a, const Complex& b)
{
    double re = a.re * b.re - a.im * b.im;
    double im = a.re * b.im + a.im * b.re;

    return Complex(re, im);
}

Complex operator /(const Complex& a, double b)
{
    return Complex(a.re / b, a.im / b);
}

Complex operator /(const Complex& a, const Complex& b)
{
    return (a * b.conjugate()) / b.abs_sqr();
}

Complex& operator +=(Complex& a, const Complex& b)
{
    return (a = a + b);
}

Complex& operator -=(Complex& a, const Complex& b)
{
    return (a = a - b);
}

Complex& operator *=(Complex& a, const Complex& b)
{
    return (a = a * b);
}

Complex& operator /=(Complex& a, const Complex& b)
{
    return (a = a / b);
}

bool operator ==(const Complex& a, const Complex& b)
{
    return a.re == b.re && a.im == b.im;
}

bool operator !=(const Complex& a, const Complex& b)
{
    return !(a == b);
}
