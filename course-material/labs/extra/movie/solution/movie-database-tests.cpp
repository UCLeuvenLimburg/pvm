#include "movie-database.h"
#include "Catch.h"


TEST_CASE("MovieDB create actor")
{
    MovieDatabase db;
    auto actor = db.create_actor("Ian McShane", Date(29, 9, 1942));
   
    CHECK(actor->name() == "Ian McShane");
    CHECK(actor->birthday() == Date(29, 9, 1942));
}

TEST_CASE("MovieDB create movie")
{
    MovieDatabase db;
    auto movie = db.create_movie("Magnolia");

    CHECK(movie->title() == "Magnolia");
}

TEST_CASE("MovieDB find existing actor")
{
    MovieDatabase db;
    auto actor = db.create_actor("Ian McShane", Date(29, 9, 1942));

    CHECK(db.find_actor("Ian McShane") == actor);
}

TEST_CASE("MovieDB find nonexisting actor")
{
    MovieDatabase db;
    auto actor = db.create_actor("Ian McShane", Date(29, 9, 1942));

    CHECK(db.find_actor("Lance Henriksen") == nullptr);
}
