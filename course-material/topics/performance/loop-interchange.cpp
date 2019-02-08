// Before
for ( int x = 0; x != width; ++x )
    for ( int y = 0; y != height; ++y )
        process( xs[y][x] );

// After
for ( int y = 0; y != height; ++y )
    for ( int x = 0; x != width; ++x )
        process( xs[y][x] );
