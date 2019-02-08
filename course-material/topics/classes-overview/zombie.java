class Foo
{
    public static Foo foo;

    @Override
    protected void finalize()
    {
        Foo.foo = this; // Uh oh
    }  
}
