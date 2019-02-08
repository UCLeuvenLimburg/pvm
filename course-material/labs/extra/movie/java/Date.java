public class Date
{
    public int day, month, year;

    public Date(int day, int month, int year)
    {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    // Implement as operator == and operator !=
    public boolean equals(Date that)
    {
        return this.day == that.day && this.month == that.month && this.year == that.year;
    }

    // Implement as << on std::ostream
    public String toString()
    {
        return String.format("%d/%d/%d", day, month, year);
    }       
}
