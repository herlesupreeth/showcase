#include <stdlib.h>
#include <stdio.h>


/* unit: 1/256 dB */
signed short g_pwrDiff[] = {
    32767,
    32766,
    16385,
    16384,
    10000,
    8888,
    4096,
    4095,
    256,
    255,
    1,
    0,
   -1,
   -2,
   -256,
   -1023,
   -1024,
   -1025,
   -4095,
   -6789,
   -12345,
   -32766,
   -32767,
   -32768
}; 


int main()
{
    unsigned short pwrDiffAbs;
    char sign;
    double gain;
    int gain2;
    int i;

    for (i=0; i<(sizeof(g_pwrDiff)/sizeof(signed short)); i++)
    {
        gain = ((double)g_pwrDiff[i] / 256);

        if (g_pwrDiff[i] & 0x8000)
        {
            pwrDiffAbs = ((g_pwrDiff[i] ^ 0xffff) + 1);
            sign = '-';
        }
        else
        {
            pwrDiffAbs = g_pwrDiff[i];
            sign = '+';
        }

        gain2 = ((pwrDiffAbs * 100) / 256);

        printf(
            "%02x%02x:  %5u, %+6d, %11lf, %c%d.%02d\n",
            ((g_pwrDiff[i] >> 8) & 0xFF),
            ((g_pwrDiff[i]     ) & 0xFF),
            (unsigned short)g_pwrDiff[i],
            g_pwrDiff[i],
            gain,
            sign,
            (gain2 / 100),
            (gain2 % 100)
        );
    }

    return 0;
}
 
