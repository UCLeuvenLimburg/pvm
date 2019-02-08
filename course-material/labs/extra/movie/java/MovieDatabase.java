import java.util.*;

class MovieDatabase
{
    private ArrayList<Actor> actors;
    private ArrayList<Movie> movies;

    public MovieDatabase()
    {
        this.actors = new ArrayList<>();
        this.movies = new ArrayList<>();
    }

    public Actor createActor(String name, Date birthday)
    {
        Actor actor = new Actor(name, birthday);
        actors.add(actor);
        return actor;
    }

    public Movie createMovie(String title)
    {
        Movie movie = new Movie(title);
        movies.add(movie);
        return movie;
    }

    public Actor findActor(String name)
    {
        for ( Actor actor : actors )
        {
            if ( name.equals(actor.name()) )
            {
                return actor;
            }
        }

        return null;
    }
}
    
