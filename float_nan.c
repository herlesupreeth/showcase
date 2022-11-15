#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double R;

    if (argc > 1)
        R = sqrt( strtod(argv[1], NULL) );
    else
        R = sqrt( -1 );

    if ( isnan(R) ) printf("NaN: ");
    printf("%f\n", R);

    return 0;
}

