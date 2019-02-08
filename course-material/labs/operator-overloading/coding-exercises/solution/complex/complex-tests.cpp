#include "complex.h"
#include "../Catch.h"


TEST_CASE("5+3i with constructor")
{
    const Complex c(5, 3);

    CHECK(c.re == Approx(5));
    CHECK(c.im == Approx(3));
}

TEST_CASE("5 with constructor")
{
    const Complex c(5);

    CHECK(c.re == Approx(5));
    CHECK(c.im == Approx(0));
}

TEST_CASE("3i with constructor")
{
    const Complex c(0, 3);

    CHECK(c.re == Approx(0));
    CHECK(c.im == Approx(3));
}

TEST_CASE("5 using implicit cast")
{
    const Complex c = 5;

    CHECK(c.re == Approx(5));
    CHECK(c.im == Approx(0));
}

TEST_CASE("7+5i with literals")
{
    const Complex c = 7 + 5_i;

    CHECK(c.re == Approx(7));
    CHECK(c.im == Approx(5));
}

TEST_CASE("7+5.3i with literals")
{
    const Complex c = 7 + 5.3_i;

    CHECK(c.re == Approx(7));
    CHECK(c.im == Approx(5.3));
}

TEST_CASE("Conjugate")
{
    const Complex a = 3 + 5_i;
    const Complex b = a.conjugate();

    CHECK(b.re == Approx(3));
    CHECK(b.im == Approx(-5));
}

TEST_CASE("Square of absolute value")
{
    const Complex a = 4 + 7_i;

    CHECK(a.abs_sqr() == Approx(4 * 4 + 7 * 7));
}

TEST_CASE("Absolute value")
{
    const Complex a = 3 + 4_i;

    CHECK(a.abs() == Approx(5));
}

TEST_CASE("Adding 5+3i and 1+7i")
{
    const Complex a = 5 + 3_i;
    const Complex b = 1 + 7_i;
    const Complex c = a + b;

    CHECK(c.re == Approx(6));
    CHECK(c.im == Approx(10));
}

TEST_CASE("Subtracting 5+3i from 11+7i")
{
    const Complex a = 5 + 3_i;
    const Complex b = 11 + 7_i;
    const Complex c = b - a;

    CHECK(c.re == Approx(6));
    CHECK(c.im == Approx(4));
}

TEST_CASE("Multiplying 5+3i and 2")
{
    const Complex a = 4 + 8_i;
    const Complex b = 2;
    const Complex c = a * b;

    CHECK(c.re == Approx(8));
    CHECK(c.im == Approx(16));
}

TEST_CASE("Multiplying 5+3i and 2i")
{
    const Complex a = 4 + 8_i;
    const Complex b = 2_i;
    const Complex c = a * b;

    CHECK(c.re == Approx(-16));
    CHECK(c.im == Approx(8));
}

TEST_CASE("Multiplying 7i and 2i")
{
    const Complex a = 7_i;
    const Complex b = 2_i;
    const Complex c = a * b;

    CHECK(c.re == Approx(-14));
    CHECK(c.im == Approx(0));
}

TEST_CASE("Dividing 7 by 2")
{
    const Complex a = 7;
    const Complex b = 2;
    const Complex c = a / b;

    CHECK(c.re == Approx(3.5));
    CHECK(c.im == Approx(0));
}

TEST_CASE("Dividing 8i by 2")
{
    const Complex a = 8_i;
    const Complex b = 2;
    const Complex c = a / b;

    CHECK(c.re == Approx(0));
    CHECK(c.im == Approx(4));
}

TEST_CASE("Dividing 8i by 2i")
{
    const Complex a = 8_i;
    const Complex b = 2_i;
    const Complex c = a / b;

    CHECK(c.re == Approx(4));
    CHECK(c.im == Approx(0));
}

TEST_CASE("Dividing 16+8i by 4i")
{
    const Complex a = 16 + 8_i;
    const Complex b = 4_i;
    const Complex c = a / b;

    CHECK(c.re == Approx(2));
    CHECK(c.im == Approx(-4));
}

TEST_CASE("Operator +=")
{
    Complex a = 5 + 3_i;
    const Complex b = 1 + 2_i;

    a += b;

    CHECK(a.re == Approx(6));
    CHECK(a.im == Approx(5));
}

TEST_CASE("Operator -=")
{
    Complex a = 5 + 3_i;
    const Complex b = 1 + 2_i;

    a -= b;

    CHECK(a.re == Approx(4));
    CHECK(a.im == Approx(1));
}

TEST_CASE("Operator *=")
{
    Complex a = 5 + 3_i;
    const Complex b = 1 + 2_i;

    a *= b;

    CHECK(a.re == Approx(-1));
    CHECK(a.im == Approx(13));
}

TEST_CASE("Operator /=")
{
    Complex a = 5 + 3_i;
    const Complex b = 1 + 2_i;

    a /= b;

    CHECK(a.re == Approx(2.2));
    CHECK(a.im == Approx(-1.4));
}

TEST_CASE("Chaining operator +=")
{
    Complex a = 5 + 3_i;
    const Complex b = 1 + 2_i;

    (a += b) += b;
    
    CHECK(a.re == Approx(7));
    CHECK(a.im == Approx(7));
}
