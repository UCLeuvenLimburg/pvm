class Foo
{
    private ImportantResource res;

    @Override
    protected void finalize()
    {
        res.close();
    }
}
