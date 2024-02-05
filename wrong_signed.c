#include <stdio.h>


void add1(int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a + b;

    printf("c = %d + %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void add2(unsigned int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a + b;

    printf("c = %d + %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void add3(int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a + b;

    printf("c = %d + %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void add4(unsigned int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a + b;

    printf("c = %d + %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}


void sub1(int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a - b;

    printf("c = %d - %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void sub2(unsigned int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a - b;

    printf("c = %d - %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void sub3(int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a - b;

    printf("c = %d - %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void sub4(unsigned int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a - b;

    printf("c = %d - %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}


void mul1(int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a * b;

    printf("c = %d * %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void mul2(unsigned int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a * b;

    printf("c = %d * %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void mul3(int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a * b;

    printf("c = %d * %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void mul4(unsigned int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a * b;

    printf("c = %d * %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}


void div1(int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a / b;

    printf("c = %d / %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void div2(unsigned int a, int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a / b;

    printf("c = %d / %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void div3(int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a / b;

    printf("c = %d / %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}

void div4(unsigned int a, unsigned int b)
{
    int c;

    printf("a = %d (0x%x)\n", a, a);
    printf("b = %d (0x%x)\n", b, b);

    c = a / b;

    printf("c = %d / %d = %d (0x%x)\n", a, b, c, c);
    printf("\n");
}


void (*g_fnc1[])(int, int) = {
    add1, sub1, mul1, div1
};

void (*g_fnc2[])(unsigned int, int) = {
    add2, sub2, mul2, div2
};

void (*g_fnc3[])(int, unsigned int) = {
    add3, sub3, mul3, div3
};

void (*g_fnc4[])(unsigned int, unsigned int) = {
    add4, sub4, mul4, div4
};

int main(int argc, char *argv[])
{
    char symb[] = { '+', '-', '*', '/' };
    int op = 3;

    if (argc > 1) op = (atoi( argv[1] ) & 0x3);

    printf("---------------------------------\n");
    printf(" (int) %c (int)\n", symb[op]);
    printf("---------------------------------\n");
    g_fnc1[op]( 300,  6);
    g_fnc1[op]( 300, -6);
    g_fnc1[op](-300,  6);
    g_fnc1[op](-300, -6);

    printf("---------------------------------\n");
    printf(" (unsigned int) %c (int)\n", symb[op]);
    printf("---------------------------------\n");
    g_fnc2[op]( 300,  6);
    g_fnc2[op]( 300, -6);
    g_fnc2[op](-300,  6);
    g_fnc2[op](-300, -6);

    printf("---------------------------------\n");
    printf(" (int) %c (unsigned int)\n", symb[op]);
    printf("---------------------------------\n");
    g_fnc3[op]( 300,  6);
    g_fnc3[op]( 300, -6);
    g_fnc3[op](-300,  6);
    g_fnc3[op](-300, -6);

    printf("---------------------------------\n");
    printf(" (unsigned int) %c (unsigned int)\n", symb[op]);
    printf("---------------------------------\n");
    g_fnc4[op]( 300,  6);
    g_fnc4[op]( 300, -6);
    g_fnc4[op](-300,  6);
    g_fnc4[op](-300, -6);

    return 0;
}

