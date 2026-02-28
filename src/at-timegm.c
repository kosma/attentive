#include <attentive/at-timegm.h>

static int is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static int days_in_month(int year, int month)
{
    static const int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 1 && is_leap_year(year)) {
        return 29;
    }
    return days[month];
}

time_t at_timegm(const struct tm *tm)
{
    int year = tm->tm_year + 1900;
    int month = tm->tm_mon;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;
    int second = tm->tm_sec;

    // Normalize month and year
    if (month > 11) {
        year += month / 12;
        month %= 12;
    } else if (month < 0) {
        int years_diff = (11 - month) / 12;
        year -= years_diff;
        month += 12 * years_diff;
    }

    // Days since Unix epoch
    int64_t days = 0;

    // Years to days
    for (int y = 1970; y < year; ++y) {
        days += is_leap_year(y) ? 366 : 365;
    }
    for (int y = year; y < 1970; ++y) {
        days -= is_leap_year(y) ? 366 : 365;
    }

    // Months to days
    for (int m = 0; m < month; ++m) {
        days += days_in_month(year, m);
    }

    // Days
    days += (day - 1);

    // Total seconds
    int64_t total_seconds = days * 86400
                           + hour * 3600
                           + minute * 60
                           + second;

    return (time_t)total_seconds;
}
