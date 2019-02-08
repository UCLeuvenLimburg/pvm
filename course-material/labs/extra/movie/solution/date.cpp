#include "date.h"


Date::Date(int day, int month, int year)
    : day(day), month(month), year(year) { }


bool Date::operator==(const Date& date) const
{
    return day == date.day && month == date.month && year == date.year;
}

bool Date::operator!=(const Date& date) const
{
    return !(*this == date);
}

std::ostream& operator <<(std::ostream& out, const Date& date)
{
    return out << date.day << "/" << date.month << "/" << date.year;
}
