#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct _tData
{
    int  id;
    char name[16];
} tData;

void show_array(tData *pObj[], int num)
{
    unsigned char *pByte;
    char string[80];
    int offset;
    int i;
    int j;

    printf("\n");
    for (i=0; i<num; i++)
    {
        offset = sprintf(string, "%p[ %p ]", &pObj[i], pObj[i]);
        pByte = (void *)pObj[i];
        printf(
            "%s -> %02x %02x %02x %02x %02x %02x %02x %02x\n",
            string,
            pByte[0], pByte[1], pByte[2], pByte[3],
            pByte[4], pByte[5], pByte[6], pByte[7]
        );
        for (j=0; j<offset; j++) string[j] = 0x20;
        printf(
            "%s    %02x %02x %02x %02x %02x %02x %02x %02x\n",
            string,
            pByte[8], pByte[9], pByte[10], pByte[11],
            pByte[12], pByte[13], pByte[14], pByte[15]
        );
        printf("%s    ...\n", string);
    }
    printf("\n");
}

void dump(void *pAddr, int size)
{
    unsigned char *pByte = pAddr;
    int i;
    int j;

    for (i=0; i<(size/16); i++)
    {
        printf("%lx : ", (unsigned long)pByte);
        for (j=0; j<16; j++)
        {
            printf(" %02x", pByte[j]);
        }
        printf(" : ");
        for (j=0; j<16; j++)
        {
            printf(
                "%c",
                ((pByte[j] >= 0x20) && (pByte[j] <= 0x7E))
                 ? (char)pByte[j]
                 : '.'
            );
        }
        printf("\n");
        pByte += 16;
    }
    printf("\n");
}

int main(void)
{
    tData *pData[4];


    pData[0] = malloc(sizeof( tData ));
    memset(pData[0], 0xFF, sizeof( tData ));
    pData[0]->id = 8000;
    sprintf(pData[0]->name, "Sunday");

    pData[1] = malloc(sizeof( tData ));
    memset(pData[1], 0xFF, sizeof( tData ));
    pData[1]->id = 8001;
    sprintf(pData[1]->name, "Monday");

    pData[2] = malloc(sizeof( tData ));
    memset(pData[2], 0xFF, sizeof( tData ));
    pData[2]->id = 8002;
    sprintf(pData[2]->name, "Tuesday");

    pData[3] = malloc(sizeof( tData ));
    memset(pData[3], 0xFF, sizeof( tData ));
    pData[3]->id = 8003;
    sprintf(pData[3]->name, "Wednesday");


    dump(pData, (sizeof( tData* ) * 4));
    dump(pData[0], 100);

    show_array(&pData[0], 4);


    free( pData[0] );
    free( pData[1] );
    free( pData[2] );
    free( pData[3] );

    return 0;
}

