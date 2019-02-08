#include "movie.h"
#include "Catch.h"


TEST_CASE("Movie constructor")
{
    Movie movie("The Prestige");

    CHECK(movie.title() == "The Prestige");
}

TEST_CASE("Movie characters")
{
    Movie movie("The Prestige");
    auto christian = std::make_shared<Actor>("Christian Bale", Date(30, 1, 1974));
    auto hugh = std::make_shared<Actor>("Hugh Jackman", Date(30, 1, 1974));

    movie.add_actor("Alfred Borden", christian);
    movie.add_actor("Robert Angier", hugh);

    CHECK(movie.title() == "The Prestige");

    auto characters = movie.characters();

    CHECK(characters.size() == 2);
    CHECK(characters.find("Alfred Borden") != characters.end());
    CHECK(characters.find("Robert Angier") != characters.end());
}

TEST_CASE("Movie actor")
{
    Movie movie("The Prestige");
    auto christian = std::make_shared<Actor>("Christian Bale", Date(30, 1, 1974));
    auto hugh = std::make_shared<Actor>("Hugh Jackman", Date(30, 1, 1974));

    movie.add_actor("Alfred Borden", christian);
    movie.add_actor("Robert Angier", hugh);

    CHECK(movie.title() == "The Prestige");

    CHECK(movie.actor("Alfred Borden") == christian);
    CHECK(movie.actor("Robert Angier") == hugh);
}
