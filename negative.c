#include <stdlib.h>
#include <stdio.h>


signed short g_neg[] = {
   -1,
   -2,
   -3,
   -256,
   -1023,
   -1024,
   -1025,
   -4095,
   -6789,
   -16384,
   -22222,
   -32766,
   -32767,
   -32768
}; 


int main()
{
    unsigned short abs;
    char sign;
    int i;

    for (i=0; i<(sizeof(g_neg)/sizeof(signed short)); i++)
    {
        if (g_neg[i] & 0x8000)
        {
            abs = ((g_neg[i] ^ 0xffff) + 1);
            sign = '-';
        }
        else
        {
            abs = g_neg[i];
            sign = '+';
        }

        printf(
            "0x%02x%02x:  %+6d, %c%u\n",
            ((g_neg[i] >> 8) & 0xFF),
            ((g_neg[i]     ) & 0xFF),
            g_neg[i],
            sign,
            abs
        );
    }

    return 0;
}
 
