#ifndef MOVIE_H
#define MOVIE_H

#include "actor.h"
#include <memory>
#include <string>
#include <map>
#include <set>


class Movie
{   
    std::string m_title;
    std::map<std::string, std::shared_ptr<Actor>> m_cast;
    
public:
    Movie(const std::string& title);
    
    std::string title() const;
    void add_actor(const std::string& character, std::shared_ptr<Actor> actor);
    std::set<std::string> characters() const;
    std::shared_ptr<Actor> actor(const std::string& character) const;
};

#endif
