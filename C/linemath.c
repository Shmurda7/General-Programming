#include <stdio.h>
#define SECONDS_PER_HOUR 3600
#define METERS_PER_MILE 1600

int main()
{
    FILE * fp;

    fp = fopen_s("csis.txt", "w");

    double distance = 275.5;
    double hours = 8.5;
    double speed = distance / hours;
    double speedms = (speed / SECONDS_PER_HOUR) * METERS_PER_MILE;

    printf("How many miles did the car travel?: \n");
    scanf_s("%lf", &distance);
    printf("%lf \nHow many hours did it take the car to travel x miles?: \n", distance);

    printf("\nThe car is traveling at x miles per hour. \n");
    printf("\nSo, this also suggests that the car is traveling at x meters per second. \n");

    fclose(fp);

    return 0;
}