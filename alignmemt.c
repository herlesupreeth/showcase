#include <stdio.h>
#include <inttypes.h>


typedef struct _tData
{
    unsigned int   A;
    unsigned char  B;
    unsigned char  C[6];
    unsigned char  D[8];
    unsigned short E;
#if 0
} tData;
#else
} __attribute__((packed)) tData;
#endif

unsigned char g_begin = 0x5a;
tData g_data = {
    .A = 588168,
    .B = 128,
    .C = { 0x1a, 0x1b, 0x1c, 0x00, 0x00, 0x01 },
    .D = { 0x2a, 0x2b, 0x2c, 0x2d, 0x00, 0x00, 0x00, 0x02 },
    .E = 0xcafe
};
unsigned int g_end = 0xefbeadde;

int main(void)
{
    unsigned long long  val64;
    unsigned char *byte;
    int  i;

    printf("\n");
    printf("&(g_begin)  = %p\n", &(g_begin));
    printf("&(g_data)   = %p\n", &(g_data));
    printf("&(g_data.A) = %p\n", &(g_data.A));
    printf("&(g_data.B) = %p\n", &(g_data.B));
    printf("&(g_data.C) = %p\n", &(g_data.C));
    printf("&(g_data.D) = %p\n", &(g_data.D));
    printf("&(g_data.E) = %p\n", &(g_data.E));
    printf("&(g_end)    = %p\n", &(g_end));
    printf("\n");

    printf("g_data.A = 0x%x\n", g_data.A);
    val64 = *((unsigned long long *)(g_data.D));
    printf("*((unsigned long long *)(g_data.D)) = 0x%llx\n", val64);
    printf("g_data.E = 0x%x\n", g_data.E);
    printf("\n");

    printf("sizeof( tData ) = %d\n", (int)sizeof( tData ));
    printf("\n");

    byte = (unsigned char *)&(g_begin);
    for (i=0; i<48; i++)
    {
        if (((i % 8) == 0) && (i != 0)) printf("\n");
        printf("%02X ", byte[i]);
    }
    printf("\n");
    printf("\n");

    return 0;
}

