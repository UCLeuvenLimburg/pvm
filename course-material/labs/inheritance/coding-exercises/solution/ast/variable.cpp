#include "variable.h"


Variable::Variable(const std::string& identifier)
    : _identifier(identifier) { }


double Variable::evaluate(const std::map<std::string, double>& context) const
{
    return context.at(this->_identifier);
}