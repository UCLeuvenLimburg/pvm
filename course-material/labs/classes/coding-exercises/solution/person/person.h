#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>


class Person
{
    std::string name;
    Person* mother;
    Person* father;
    std::vector<Person*> children;

public:
    Person(const std::string&);
    Person(const std::string&, Person*, Person*);

    std::string get_name() const;

    std::vector<Person*> get_grandchildren() const;
    bool is_ancestor(const Person&) const;
    bool is_descendant(const Person&) const;
};

#endif
