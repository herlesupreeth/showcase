#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


unsigned long long double2bin(double fraction, int bits)
{
    unsigned long long val64 = 0;
    int len = 0;
    int digit;


    if (0.0 != fraction)
    {
        while (fraction - (int)fraction)
        {
            digit = (int)(fraction * 2);

            val64 = ((val64 << 0x1) | (unsigned long long)(digit & 0x1));
            len++;

            if (len >= bits) return val64;

            fraction = ((fraction * 2) - digit);
        }

        while (len++ < bits)
        {
            val64 <<= 0x1;
        }
    }

    return val64;
}

int main(int argc, char *argv[])
{
    unsigned long long  val64;
    char *pDec = NULL;
    int   bits = 32;


    if (3 == argc)
    {
        pDec = argv[1];
        bits = atoi( argv[2] );
        if (bits > 64) bits = 64;
    }
    else if (2 == argc)
    {
        pDec = argv[1];
    }
    else
    {
        printf("Usage: fra2bin FRACTION BITS\n\n");
        return -1;
    }

    val64 = double2bin(atof( pDec ), bits);
    printf("0x%llx (%d bits)\n", val64, bits);


    return 0;
}

