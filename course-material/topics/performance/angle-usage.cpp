angle<rad> a = 1.2;
angle<deg> b = 180;

angle<deg> c = b + b; // ok
angle<rad> d = a + b; // compile error
