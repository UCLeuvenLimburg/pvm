void foo(bool x = false, int y = 5);

foo(2);
// is same as
foo(true, 5);
// because 2 is implicitly converted
// to a bool with value true
