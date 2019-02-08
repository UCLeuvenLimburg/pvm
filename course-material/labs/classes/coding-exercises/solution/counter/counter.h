#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
    unsigned value;

public:
    Counter();
    Counter(unsigned);

    void increment();
    unsigned getValue() const;
    void setValue(unsigned);
    void reset();
};

#endif