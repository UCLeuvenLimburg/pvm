Duration operator "" _s(long double x) {
    return Duration::from_seconds((double) x);
}

Duration operator "" _minutes(long double x) {
    return Duration::from_seconds((double) x);
}

Duration operator "" _hours(long double x) {
    return Duration::from_hours((double) x);
}

// Usage
Duration d1 = 5_s, d2 = 10_hours;
