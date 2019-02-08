#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    double re, im;

    Complex(double re, double im = 0) : re(re), im(im) { }

    double abs_sqr() const;
    double abs() const;
    Complex conjugate() const;
};

Complex operator"" _i(long long unsigned);
Complex operator"" _i(long double);

Complex operator +(const Complex&, const Complex&);
Complex operator -(const Complex&);
Complex operator -(const Complex&, const Complex&);
Complex operator *(const Complex&, const Complex&);
Complex operator /(const Complex&, const Complex&);
Complex operator /(const Complex&, double);

Complex& operator +=(Complex&, const Complex&);
Complex& operator -=(Complex&, const Complex&);
Complex& operator *=(Complex&, const Complex&);
Complex& operator /=(Complex&, const Complex&);

bool operator ==(const Complex&, const Complex&);
bool operator !=(const Complex&, const Complex&);

#endif
