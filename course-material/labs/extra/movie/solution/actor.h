#ifndef ACTOR_H
#define ACTOR_H

#include "date.h"
#include <string>
#include <vector>


class Actor
{
    std::string m_name;
    Date m_birthday;

public:
    Actor(const std::string& name, const Date& birthday);

    std::string name() const;
    Date birthday() const;
};

#endif
