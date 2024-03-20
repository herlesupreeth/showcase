#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double x, y;

    x = +0.0; y = +0.0;
    printf("atan2(%+f, %+f) = %+f\n", y, x, atan2(y, x));

    x = +0.0; y = -0.0;
    printf("atan2(%+f, %+f) = %+f\n", y, x, atan2(y, x));

    x = -0.0; y = +0.0;
    printf("atan2(%+f, %+f) = %+f\n", y, x, atan2(y, x));

    x = -0.0; y = -0.0;
    printf("atan2(%+f, %+f) = %+f\n", y, x, atan2(y, x));

    return 0;
}
