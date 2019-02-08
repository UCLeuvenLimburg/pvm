#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <string>


class Expression
{
public:
    virtual double evaluate(const std::map<std::string, double>&) const = 0;
};

#endif
