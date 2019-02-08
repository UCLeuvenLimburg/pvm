#ifndef ADDITION_H
#define ADDITION_H

#include "operator.h"


class Addition : public Operator
{
public:
    Addition(const std::vector<std::shared_ptr<const Expression>>&);

    double evaluate(const std::map<std::string, double>&) const override;
};

#endif
