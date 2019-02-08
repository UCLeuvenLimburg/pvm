#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int _value, _step;
    
public:
    Counter(int value = 0, int step = 0)
        : _value(value), _step(step) { }

    void reset();

    // Default values have to be compile-time constants
    // meaning you can't use default arguments here
    void increment(int step);
    void increment();

    int value() const;
    int step() const;
};

#endif
