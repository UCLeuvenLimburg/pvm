#include "person.h"
#include <algorithm>


Person::Person(const std::string& name) : Person(name, nullptr, nullptr)
{
    // NOP
}

Person::Person(const std::string& name, Person* mother, Person* father)
    : name(name), mother(mother), father(father)
{
    if (mother != nullptr)
    {
        mother->children.push_back(this);
    }

    if (father != nullptr)
    {
        father->children.push_back(this);
    }
}

std::string Person::get_name() const
{
    return this->name;
}

std::vector<Person*> Person::get_grandchildren() const
{
    std::vector<Person*> result;

    for (auto child : children)
    {
        result.insert(result.end(), child->children.begin(), child->children.end());
    }

    return result;
}

bool Person::is_ancestor(const Person& person) const
{
    return mother == &person || father == &person || (mother != nullptr && mother->is_ancestor(person)) || (father != nullptr && father->is_ancestor(person));
}

bool Person::is_descendant(const Person& person) const
{
    if (std::find(children.begin(), children.end(), &person) != children.end())
    {
        return true;
    }
    else
    {
        return std::any_of(children.begin(), children.end(), [&person](const Person* child) { return child->is_descendant(person); });
    }
}
