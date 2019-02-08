#ifndef MOVIE_DATABASE_H
#define MOVIE_DATABASE_H

#include "movie.h"
#include <memory>


class MovieDatabase
{
    std::vector<std::shared_ptr<Actor>> m_actors;
    std::vector<std::shared_ptr<Movie>> m_movies;

public:
    std::shared_ptr<Actor> create_actor(const std::string& name, const Date& birthday);
    std::shared_ptr<Movie> create_movie(const std::string& title);

    std::shared_ptr<Actor> find_actor(const std::string& name) const;
};

#endif
