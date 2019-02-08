template<typename Iterator>
void zero(Iterator start, Iterator end)
{
    while ( start != end )
    {
        *start = 0;
        ++start;
    }
}
