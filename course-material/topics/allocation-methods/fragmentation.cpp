const int N = 10000;
int* p[N];

// Allocate many small arrays
for ( int i = 0; i < N; ++i )
  p[i] = new int[1];

// Free half of them
for ( int i = 0; i < N; i += 2 )
  delete[] p[i];

