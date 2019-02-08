#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int _value, _step;
    
public:
    Counter()
        : Counter(0) { }

    Counter(int value)
        : Counter(value, 0) { }

    Counter(int value, int step)
        : _value(value), _step(step) { }

    void reset();

    void increment(int);
    void increment();

    int value() const;
    int step() const;
};

#endif
