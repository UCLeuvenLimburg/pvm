class Predicate {
public:
    virtual bool check(int x) const = 0;
};

int count(int max,
          const Predicate* predicate) {
    int result = 0;

    for (int i = 0; i != max; ++i)
        if (predicate->check(i)) ++result;

    return result;
}
