#ifndef DATE_H
#define DATE_H

#include <iostream>


struct Date
{
    int day, month, year;

    Date(int day, int month, int year);

    bool operator ==(const Date&) const;
    bool operator !=(const Date&) const;
};

std::ostream& operator <<(std::ostream& out, const Date& date);

#endif
