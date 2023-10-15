#include <stdio.h>
#define SECONDS_PER_HOUR 3600
#define METERS_PER_MILE 1600

int main()
{
    double distance = 275.5;
    double hours = 8.5;
    double speed = distance / hours;
    double speedms = (speed / SECONDS_PER_HOUR) * METERS_PER_MILE;

    FILE *fp;
    int result = fopen_s(&fp, "output.txt", "w");

    if (result == 0)
    {
        fprintf(fp, "The car traveled %lf miles in %lf hours\n", distance, hours);
        fprintf(fp, "The car's speed was %lf miles/hour\n", speed);
        fprintf(fp, "The car's speed was %lf meters/second\n", speedms);

        fclose(fp);
    }
    else
    {
        printf("Could not open file. Error code: %d\n", result);
    }

    return 0;
}