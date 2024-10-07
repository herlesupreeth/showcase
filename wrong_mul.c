#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    double result1 = 57856;
    double result2;
    double result3;
    double msec = 0.1808;
    unsigned char *p;
    unsigned int num;
    int fs = 320;

    num = result1;
    printf("%u <- %f\n", num, result1);

    result2 = (msec * 1000000 * fs) / 1000;
    num = result2;
    printf("%u <- %f = (%f * 1000000 * %d) / 1000\n", num, result2, msec, fs);

    result3 = (msec * 1000 * fs);
    num = result3;
    printf("%u <- %f = (%f * 1000 * %d)\n\n", num, result3, msec, fs);

    p = (unsigned char *)&result1;
    printf(
        "result1: %02x %02x %02x %02x %02x %02x %02x %02x\n",
        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]
    );
    p = (unsigned char *)&result2;
    printf(
        "result2: %02x %02x %02x %02x %02x %02x %02x %02x\n",
        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]
    );
    p = (unsigned char *)&result3;
    printf(
        "result3: %02x %02x %02x %02x %02x %02x %02x %02x\n\n",
        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]
    );

    return 0;
}
