// Correct
void foo(int x    , int y    , int z    );
void foo(int x    , int y    , int z = 0);
void foo(int x    , int y = 0, int z = 0);
void foo(int x = 0, int y = 0, int z = 0);

// Wrong
void foo(int x = 0, int y    , int z    );
void foo(int x    , int y = 0, int z    );
void foo(int x = 0, int y = 0, int z    );
