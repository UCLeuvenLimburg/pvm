class Person
{
    private int _age;

    int& age()
    {
        return _age;
    }
};

Person p;
p.age() = 5;
