#include <stdio.h>

#define htonll(a) change_order(a)
#define ntohll(a) change_order(a)

unsigned long long change_order(unsigned long long in)
{
    unsigned long long out = 0;
    int test = 123;

    if (123 == *((unsigned char *)&test))
    {
        /* Little Endian */
        out |= (((in >> 56) & 0xFF)      );
        out |= (((in >> 48) & 0xFF) <<  8);
        out |= (((in >> 40) & 0xFF) << 16);
        out |= (((in >> 32) & 0xFF) << 24);
        out |= (((in >> 24) & 0xFF) << 32);
        out |= (((in >> 16) & 0xFF) << 40);
        out |= (((in >>  8) & 0xFF) << 48);
        out |= (((in      ) & 0xFF) << 56);
    }
    else
    {
        /* Big Endian */
        out = in;
    }

    return out;
}

int main(int argc, char *argv[])
{
    int host = 0x11223344;
    int network = 0x44332211;

    printf("      Host 0x%x (%02x %02x %02x %02x)\n",
           host,
           ((unsigned char *)&host)[0],
           ((unsigned char *)&host)[1],
           ((unsigned char *)&host)[2],
           ((unsigned char *)&host)[3]
    );
    printf("-> Network 0x%llx\n\n", htonll(host));

    printf("   Network 0x%x (%02x %02x %02x %02x)\n",
           network,
           ((unsigned char *)&network)[0],
           ((unsigned char *)&network)[1],
           ((unsigned char *)&network)[2],
           ((unsigned char *)&network)[3]
    );
    printf("->    Host 0x%llx\n", ntohll(network));

    return 0;
}

