template<typename Predicate>
int count(int max)
{
    int result = 0;
    Predicate p;

    for (int i = 0; i != max; ++i)
        if (p(i)) ++result;

    return result;
}
