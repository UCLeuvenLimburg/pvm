#include "zero-cost-abstractions.h"
#include "shared.h"
#include <type_traits>
#include <iostream>
#include <math.h>


namespace
{
    struct rad { };
    struct deg { };

    template<typename> struct is_angle_unit : std::false_type { };
    template<> struct is_angle_unit<rad> : std::true_type { };
    template<> struct is_angle_unit<deg> : std::true_type { };

    template<typename UNIT, typename Enable = void>
    class angle { };

    template<typename UNIT>
    struct angle<UNIT, typename std::enable_if<is_angle_unit<UNIT>::value>::type>
    {
        angle() : angle(0) { }
        explicit angle(double size) : size(size) { }

        double size;
    };

    template<typename T>
    angle<T> operator +(angle<T> a, angle<T> b)
    {
        return angle<T>(a.size + b.size);
    }

    template<typename T>
    angle<T>& operator +=(angle<T>& a, angle<T> b)
    {
        return a = a + b;
    }

    template<typename T>
    bool operator <(angle<T> a, angle<T> b)
    {
        return a.size < b.size;
    }

    angle<deg> to_degrees(angle<rad> a)
    {
        return angle<deg>(a.size / 3.141592 * 180);
    }

    angle<rad> to_radians(angle<deg> a)
    {
        return angle<rad>(a.size * 3.141592 / 180);
    }

    double sin(angle<rad> a)
    {
        return ::sin(a.size);
    }

    double sum_double()
    {
        double result = 0;

        for (double x = 0; x < 2 * 3.141592; x += 0.0000001)
        {
            result += ::sin(x);
        }

        return result;
    }

    double sum_angle()
    {
        double result = 0;

        for (angle<rad> x(0); x < angle<rad>(2 * 3.141592); x += angle<rad>(0.0000001))
        {
            result += sin(x);
        }

        return result;
    }
}

void test_zero_cost_abstractions()
{
    double r1, r2;

    auto d1 = measure_time<double>(sum_double, &r1);
    auto d2 = measure_time<double>(sum_angle, &r2);

    std::cout << "With doubles: " << d1 << " [" << r1 << "]" << std::endl;
    std::cout << "With angles: " << d2 << " [" << r2 << "]" << std::endl;
}