#include "bits.h"
#include <algorithm>


void Bits::append(bool bit)
{
    m_bits.push_back(bit);
}

void Bits::drop_last()
{
    m_bits.pop_back();
}

void Bits::concatenate(const Bits& bits)
{
    for (auto b : bits.m_bits)
    {
        m_bits.push_back(b);
    }
}

unsigned Bits::size() const
{
    return m_bits.size();
}

bool Bits::operator [](unsigned index) const
{
    return m_bits[index];
}

std::ostream& operator <<(std::ostream& out, const Bits& bits)
{
    for ( unsigned i = 0; i != bits.size(); ++i )
    {
        out << bits[i] ? "1" : "0";
    }

    return out;
}
