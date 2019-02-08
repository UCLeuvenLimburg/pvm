#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"
#include <string>


class Variable : public Expression
{
    std::string _identifier;

public:
    Variable(const std::string&);

    double evaluate(const std::map<std::string, double>&) const override;
};

#endif
