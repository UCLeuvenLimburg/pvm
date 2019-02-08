#include "multiplication.h"


Multiplication::Multiplication(const std::vector<std::shared_ptr<const Expression>>& operands)
    : Operator(operands) { }


double Multiplication::evaluate(const std::map<std::string, double>& context) const
{
    double result = 1;

    for (auto operand : _operands)
    {
        result *= operand->evaluate(context);
    }

    return result;
}