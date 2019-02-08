#ifndef MAX_H
#define MAX_H


template<typename T>
T& max(T& x, T& y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

template<typename T>
const T& max(const T& x, const T& y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

#endif
