#include <stdbool.h>
#include <stdio.h>

double minutes_to_hours(int minutes) {
    return minutes / 60;
}

double minutes_to_days(int minutes) {
    return minutes_to_hours(minutes) / 24;
}

double minutes_to_years(int minutes) {
    return minutes_to_days(minutes) / 365;
}

int main(int argc, char *argv[]) {
    int minutes;

    printf("Please enter the minutes to be converted: ");
    scanf("%d", &minutes);

    long double hours = minutes_to_hours(minutes);
    long double days = minutes_to_days(minutes);
    long double years = minutes_to_years(minutes);

    printf("%d minutes equals %d hours, %d days and %d years\n", minutes, (int)hours, (int)days, (int)years);
    printf("%d minutes equals %.5Lf hours, %.5Lf days and %.5Lf years\n", minutes, hours, days, years);

    return 0;
}