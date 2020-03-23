#ifndef NUMBER_SET_H
#define NUMBER_SET_H

#include <cstdint>


class NumberSet
{
private:
    uint32_t contents;

public:
    NumberSet();

    void add(unsigned);
    void remove(unsigned);
    bool contains(unsigned) const;
    void intersection(const NumberSet&);
    void union_with(const NumberSet&);
    unsigned size() const;
};

#endif
