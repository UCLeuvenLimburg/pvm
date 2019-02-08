class Duration
{
public:
    static Duration from_seconds(double);
    static Duration from_minutes(double);
    static Duration from_hours(double);
    static Duration from_days(double);
    // ...
};


auto d = Duration::from_seconds(5.3);
