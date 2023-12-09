#include <stdio.h>
#include <math.h>

void mod1(int a, int b)
{
    int c;

    c = a % b;
    printf("%d = %d %% %d\n", c, a, b);
}

void mod2(double a, double b)
{
    double c;

    c = fmod(a, b);
    printf("%f = fmod(%f, %f)\n", c, a, b);
}

void mod3(int a, int b)
{
    int c;

    c = (a - (b * floor((double)a / (double)b)));
    printf("%d = %d - (%d * floor(%d / %d))\n", c, a, b, a, b);
}

void mod4(double a, double b)
{
    double c;

    c = (a - (b * floor(a / b)));
    printf("%f = %f - (%f * floor(%f / %f))\n", c, a, b, a, b);
}

int main(void)
{
    /*
    *  a / d =  q ...  r
    * -1 / 4 = -1 ...  3, remainder
    *        =  0 ... -1, modulo
    *  q = floor( a / d),  a =  q * d + r, r =  a - (q * d)
    * -1 = floor(-1 / 4), -1 = -1 * 4 + r, r =  3
    *  0 = fix(-1 / 4), -1 =  0 * 4 + r, r = -1
    */

    printf("remainder:\n");
    mod1(-1, 4);
    mod2(-1, 4);
    printf("\n");

    printf("modulo:\n");
    mod3(-1, 4);
    mod4(-1, 4);
    printf("\n");

    return 0;
}

