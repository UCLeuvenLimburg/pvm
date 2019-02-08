#include "addition.h"


Addition::Addition(const std::vector<std::shared_ptr<const Expression>>& operands)
    : Operator(operands) { }


double Addition::evaluate(const std::map<std::string, double>& context) const
{
    double result = 0;

    for (auto operand : _operands)
    {
        result += operand->evaluate(context);
    }

    return result;
}