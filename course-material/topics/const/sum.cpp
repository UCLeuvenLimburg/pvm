// Only needs read access to work
int sum(const std::vector<int>* ns)
{
    int result = 0;

    for ( int n : *ns )
        result += n;

    return result;
}
