#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long long  val64;
    unsigned short  val16;

    val16 = 45;
    if (argc > 1) val16 = atoi( argv[1] );
    printf("   val16 = %u\n", val16);

    val64 = (val16 * 1000000000);
    printf("1) val64 = val16 * 1000000000 = %llu (0x%llx)\n", val64, val64);

    val64 = (val16 * 1000000000ULL);
    printf("2) val64 = val16 * 1000000000ULL = %llu (0x%llx)\n", val64, val64);
    printf("\n");

    return 0;
}

