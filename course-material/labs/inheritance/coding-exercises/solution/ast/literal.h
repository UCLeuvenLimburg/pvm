#ifndef LITERAL_H
#define LITERAL_H

#include "expression.h"


class Literal : public Expression
{
    double _value;

public:
    Literal(double);

    double evaluate(const std::map<std::string, double>&) const override;
};

#endif
