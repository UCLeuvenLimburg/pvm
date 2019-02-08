// Three different containers
std::vector<int> vec {1, 2, 3, 4, 5};
std::list<int> lst {1, 2, 3, 4, 5};
std::set<int> set {1, 2, 3, 4, 5};

// Same function works on each of them
zero(vec.begin(), vec.end());
zero(lst.begin(), lst.end());
zero(set.begin(), set.end());
