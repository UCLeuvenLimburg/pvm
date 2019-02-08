// Before
for ( int i = 0; i != imax; ++i )
{
    int k = i * 10;
    // ...
}

// After
int k = 0;
for ( int i = 0; i != imax; ++i )
{
    k += 10;
    // ...
}
