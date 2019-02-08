std::vector<int> xs, ys; // same size

// Before
for ( int i = 0; i != xs.size(); ++i ) {
    process(xs[i]);
    process(ys[i]);
}

// After
for ( int i = 0; i != xs.size(); ++i )
    process(xs[i]);

for ( int i = 0; i != xs.size(); ++i )
    process(ys[i]);

