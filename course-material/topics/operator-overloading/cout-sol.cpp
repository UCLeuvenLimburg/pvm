std::ostream& operator <<(ostream& out,
                          const Date& date)
{
    out << date.day
        << "/"
        << date.month
        << "/"
        << date.year;

    return out;
}
