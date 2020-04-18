# Assignment

An angle is typically expressed using a `double`.
This is a bit dangerous though: angles can be expressed in both radians and degrees.
Degrees are generally more readable for humans, but library functions often require radians.
For this reason, we introduce a class `angle` to be used as a replacement for `double` when modelling angles.

Internally, the `angle` class will store the angle size in radians.
When asking for the angle's size, one must always explicitly mention if it should be expressed in degrees or radians:

```c++
angle a;

double x = a.in_radians();
double y = a.in_degrees();
```

## Example Usage

```c++
// Using static factory functions
angle a = angle::from_radians(1.5);

// Using custom literal
angle b = 120_deg;

// Getting size
double x = a.in_radians();
double y = b.in_degrees();

// Operations
angle c = a + b;
angle d = a * 5;

// Comparison
a < b
a >= b
a != b
```

## Functionality

The class `angle` must provide the following functionality:

* A [static](https://en.cppreference.com/w/cpp/language/static) factory function `from_degrees(size)`.
* A static factory function `from_radians(size)`.
* Angle [literals](https://en.cppreference.com/w/cpp/language/user_literal): `50_deg` or `1.5_rad` should be interpreted as angles in degrees and radians, respectively.
* Querying the size: `in_degrees()` and `in_radians()`.
* Operators
  * `angle + angle`
  * `angle - angle`
  * `angle * double`
  * `double * angle`
  * `angle / double`
* Comparisons `==`, `!=`, `<`, `>`, `<=`, `>=`.
* Output to stream: `ostream << angle`.