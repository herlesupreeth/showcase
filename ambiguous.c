#include <stdio.h>

int main(void)
{
    int x = 1;

    /*
    * ambiguous.c: In function ‘main’:
    * ambiguous.c:12: warning: operation on ‘x’ may be undefined
    * ambiguous.c:12: warning: operation on ‘x’ may be undefined
    */
    printf("%d %d %d\n", ++x, x, x++);

    return 0;
}
