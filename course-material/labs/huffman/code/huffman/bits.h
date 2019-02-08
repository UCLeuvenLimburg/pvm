#ifndef BITS_H
#define BITS_H

#include <iostream>
#include <vector>


class Bits
{
    std::vector<bool> m_bits;

public:
    void append(bool bit);
    void drop_last();
    void concatenate(const Bits& bits);

    unsigned size() const;
    bool operator [](unsigned) const;
};

std::ostream& operator <<(std::ostream&, const Bits&);

#endif
