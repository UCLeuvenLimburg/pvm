#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operator.h"


class Multiplication : public Operator
{
public:
    Multiplication(const std::vector<std::shared_ptr<const Expression>>&);

    double evaluate(const std::map<std::string, double>&) const override;
};

#endif
