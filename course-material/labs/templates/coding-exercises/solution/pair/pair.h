#ifndef PAIR_H
#define PAIR_H


template<typename T1, typename T2>
struct Pair
{
    Pair() = default;
        
    Pair(T1 first, T2 second)
        : first(first), second(second) { }

    T1 first;
    T2 second;
};

#endif
