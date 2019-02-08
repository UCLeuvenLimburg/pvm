struct Date
{
    int day, month, year;
};

// Day of the devil
Date date(6, 9, 1993);

// We want this to print "6/9/1993"
std::cout << date;
