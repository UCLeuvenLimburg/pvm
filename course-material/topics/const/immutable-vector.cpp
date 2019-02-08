const std::vector<int> ns {1, 2, 3};

int size = ns.size();   // Ok
int x = size[0];        // Ok
size.push_back(4);      // Error!

