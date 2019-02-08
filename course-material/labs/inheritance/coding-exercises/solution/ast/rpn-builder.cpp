#include "rpn-builder.h"


RPNBuilder& RPNBuilder::literal(double x)
{
    this->_stack.push(std::make_shared<const Literal>(x));

    return *this;
}

RPNBuilder& RPNBuilder::variable(const std::string& identifier)
{
    this->_stack.push(std::make_shared<const Variable>(identifier));

    return *this;
}

RPNBuilder& RPNBuilder::add()
{
    auto x = this->_stack.top();
    this->_stack.pop();
    auto y = this->_stack.top();
    this->_stack.pop();

    std::vector<std::shared_ptr<const Expression>> operands{ x, y };

    this->_stack.push(std::make_shared<const Addition>(operands));

    return *this;
}

RPNBuilder& RPNBuilder::multiply()
{
    auto x = this->_stack.top();
    this->_stack.pop();
    auto y = this->_stack.top();
    this->_stack.pop();

    std::vector<std::shared_ptr<const Expression>> operands{ x, y };

    this->_stack.push(std::make_shared<const Multiplication>(operands));

    return *this;
}

std::shared_ptr<const Expression> RPNBuilder::build() const
{
    return this->_stack.top();
}
