#ifndef INTERVAL_H
#define INTERVAL_H

class Interval
{
private:
    double lower;
    double upper;

public:
    Interval(double lower, double upper);

    double lower_bound() const;
    double upper_bound() const;

    void set_lower_bound(double lower_bound);
    void set_upper_bound(double upper_bound);

    bool contains(double x) const;
};

#endif
