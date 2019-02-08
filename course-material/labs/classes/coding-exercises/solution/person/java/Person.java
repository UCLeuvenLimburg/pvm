import java.util.*;


public class Person
{
    private String name;
    private Person mother;
    private Person father;
    private ArrayList<Person> children;

    public Person(String name)
    {
        this(name, null, null);
    }

    public Person(String name, Person mother, Person father)
    {
        this.name = name;
        this.mother = mother;
        this.father = father;
        this.children = new ArrayList<>();

        if ( mother != null )
        {
            mother.children.add(this);
        }

        if ( father != null )
        {
            father.children.add(this);
        }
    }

    public String getName()
    {
        return name;
    }

    public ArrayList<Person> getGrandchildren()
    {
        ArrayList<Person> result = new ArrayList<>();

        for ( Person child : children )
        {
            result.addAll(child.children);
        }

        return result;
    }

    public boolean isAncestor(Person person)
    {
        return mother == person || father == person || (mother != null && mother.isAncestor(person)) || (father != null && father.isAncestor(person));
    }

    public boolean isDescendant(Person person)
    {
        if ( children.contains(person) )
        {
            return true;
        }
        else
        {
            for ( Person child : children )
            {
                if ( child.isDescendant(person) )
                {
                    return true;
                }
            }

            return false;
        }
    }
}
