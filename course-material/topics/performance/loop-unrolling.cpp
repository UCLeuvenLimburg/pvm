// Before
for ( int i = 0; i != imax; ++i )
{
    foo(i);
}

// After
for ( int i = 0; i != imax; i += 4 )
{
    foo(i);
    foo(i+1);
    foo(i+2);
    foo(i+3);
}
