#ifndef OPERATOR_H
#define OPERATOR_H

#include "expression.h"
#include <vector>
#include <memory>


class Operator : public Expression
{
protected:
    std::vector<std::shared_ptr<const Expression>> _operands;

public:
    Operator(const std::vector<std::shared_ptr<const Expression>>&);
};

#endif
