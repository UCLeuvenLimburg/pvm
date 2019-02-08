#include "literal.h"


Literal::Literal(double value)
    : _value(value) { }


double Literal::evaluate(const std::map<std::string, double>&) const
{
    return this->_value;
}
