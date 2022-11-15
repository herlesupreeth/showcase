#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double R;

    if (argc > 1)
        R = log10( strtod(argv[1], NULL) );
    else
        R = log10( 0 );

    if ( isinf(R) ) printf("INF: ");
    printf("%f\n", R);

    return 0;
}

