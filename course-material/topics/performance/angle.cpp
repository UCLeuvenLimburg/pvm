struct deg { };
struct rad { };

template<typename UNIT>
class angle {
    explicit angle(double value)
        : value(value) { }
    
    double value;
};

template<typename T>
angle<T> operator +(angle<T> a, angle<T> b)
{
    return angle<T>(a.size + b.size);
}
