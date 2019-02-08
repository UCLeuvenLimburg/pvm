#include "movie.h"


Movie::Movie(const std::string& title)
    : m_title(title) 
{ 
    // NOP
}

void Movie::add_actor(const std::string& character, std::shared_ptr<Actor> actor)
{
    m_cast[character] = actor;
}

std::set<std::string> Movie::characters() const
{
    std::set<std::string> result;

    for (auto pair : m_cast)
    {
        result.insert(pair.first);
    }

    return result;
}

std::shared_ptr<Actor> Movie::actor(const std::string& character) const
{
    return m_cast.at(character);
}

std::string Movie::title() const
{
    return m_title;
}