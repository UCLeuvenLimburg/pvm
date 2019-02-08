class Actor
{
    private String name;
    private Date birthday;

    public Actor(String name, Date birthday)
    {
        this.name = name;
        this.birthday = birthday;
    }

    String name() { return name; }

    Date birthday() { return birthday; }
}
