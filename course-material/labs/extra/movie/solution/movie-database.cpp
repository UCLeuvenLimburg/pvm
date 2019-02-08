#include "movie-database.h"


std::shared_ptr<Actor> MovieDatabase::create_actor(const std::string& name, const Date& birthday)
{
    auto actor = std::make_shared<Actor>(name, birthday);

    m_actors.push_back(actor);

    return actor;
}

std::shared_ptr<Movie> MovieDatabase::create_movie(const std::string& title)
{
    auto movie = std::make_shared<Movie>(title);

    m_movies.push_back(movie);

    return movie;
}

std::shared_ptr<Actor> MovieDatabase::find_actor(const std::string& name) const
{
    for (auto p : m_actors)
    {
        if (p->name() == name)
        {
            return p;
        }
    }

    return nullptr;
}
