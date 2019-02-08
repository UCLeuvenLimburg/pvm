#ifndef RPN_BUILDER_H
#define RPN_BUILDER_H

#include "expression.h"
#include "literal.h"
#include "variable.h"
#include "addition.h"
#include "multiplication.h"
#include <stack>
#include <string>


class RPNBuilder
{
    std::stack<std::shared_ptr<const Expression>> _stack;

public:
    RPNBuilder& literal(double);
    RPNBuilder& variable(const std::string&);
    RPNBuilder& add();
    RPNBuilder& multiply();

    std::shared_ptr<const Expression> build() const;
};

#endif
