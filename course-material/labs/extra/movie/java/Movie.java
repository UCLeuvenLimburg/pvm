import java.util.*;


class Movie
{
    private String title;
    private HashMap<String, Actor> cast;

    public Movie(String title)
    {
        this.title = title;
        this.cast = new HashMap<>();
    }

    public String title()
    {
        return title;
    }

    public void addActor(String character, Actor actor)
    {
        cast.put(character, actor);
    }

    public Set<String> characters()
    {
        return cast.keySet();
    }

    public Actor actor(String character)
    {
        return cast.get(character);
    }
}
