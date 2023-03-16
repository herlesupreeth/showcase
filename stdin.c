#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define DO_READ    1
#define DO_SCANF   1
#define DO_GETCHAR 1
#define DO_GETC    1
#define DO_FGETS   1
#define DO_GETLINE 1


unsigned char g_buf[256];

void dump(char *func, unsigned char *data, size_t size)
{
    int len;
    int i;

    len = (size < 16) ? 16 : size;

    printf("[1;36m%s:[0m\n", func);
    for (i=0; i<len; i++)
    {
        printf(" %02X", data[i]);
    }
    printf("\n");
    printf(" (%ld)\n\n", size);
}

int main(void)
{
    char *line;
    size_t len;
    int n;


    #if DO_READ
    /*
    *  1  2  3  4  5  6
    *  H  e  l  l  o \n
    */
    memset(g_buf, 0xFF, 256);
    len = read(STDIN_FILENO, g_buf, 256);
    if (len > 0)
    {
        dump("read", g_buf, len);
    }
    #endif

    #if DO_SCANF
    /*
    *  1  2  3  4  5  6
    *  H  e  l  l  o \0
    */
    memset(g_buf, 0xFF, 256);
    scanf("%s", g_buf);
    len = strlen( (char *)g_buf );
    if (len > 0)
    {
        dump("scanf", g_buf, (len + 1));
    }
    #endif

    #if DO_GETCHAR
    /*
    *  1  2  3  4  5  6
    *  H  e  l  l  o \n
    */
    memset(g_buf, 0xFF, 256);
    n = 0;
    do
    {
        g_buf[n] = getchar();
    } while (g_buf[n++] != '\n');
    dump("getchar", g_buf, n);
    #endif

    #if DO_GETC
    /*
    *  1  2  3  4  5  6
    *  H  e  l  l  o \n
    */
    memset(g_buf, 0xFF, 256);
    n = 0;
    do
    {
        g_buf[n] = getc( stdin );
    } while (g_buf[n++] != '\n');
    dump("getc", g_buf, n);
    #endif

    #if DO_FGETS
    /*
    *  1  2  3  4  5  6  7
    *  H  e  l  l  o \n \0
    */
    memset(g_buf, 0xFF, 256);
    fgets((char *)g_buf, 256, stdin);
    len = strlen( (char *)g_buf );
    if (len > 0)
    {
        dump("fgets", g_buf, (len + 1));
    }
    #endif

    #if DO_GETLINE
    /*
    *  1  2  3  4  5  6  7
    *  H  e  l  l  o \n \0
    */
    len = 0;
    line = NULL;
    if (getline(&line, &len, stdin) > 0)
    {
        dump("getline", (void *)line, len);
    }
    free( line );
    #endif


    return 0;
}
