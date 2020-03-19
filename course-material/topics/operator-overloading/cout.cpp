struct Date
{
    int day, month, year;
};

// Day of the solipsistic man
Date date(19, 3, 1983);

// We want this to print "19/3/1983"
std::cout << date;
