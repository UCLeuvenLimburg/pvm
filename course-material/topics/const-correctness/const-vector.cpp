const vector<int> xs = {1, 2, 3};

int x = xs[0];     // ok
xs.size();         // ok
xs[0] = 5;         // error
xs.push_back(4);   // error
