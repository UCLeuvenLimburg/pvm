#include "actor.h"


Actor::Actor(const std::string& name, const Date& birthday)
    : m_name(name), m_birthday(birthday)
{
    // NOP
}

std::string Actor::name() const
{
    return m_name;
}

Date Actor::birthday() const
{
    return m_birthday;
}
