struct Foo
{
    void frobnicate();
};

smart_pointer<Foo> p(new Foo);

// -> is rerouted to the pointee Foo
p->frobnicate();
