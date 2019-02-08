#include "operator.h"


Operator::Operator(const std::vector<std::shared_ptr<const Expression>>& operands)
    : _operands(operands) { }
