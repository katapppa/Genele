#define MOD(x) (x < 0 ? -x : x)
#include <stdio.h>

int     main()
{
    int a;
    int b;
    int max;

    a = -8;
    b = 6;
    printf("A IS %d\n",a);
    printf("B IS %d\n",b);
    max = ((MOD(a) > MOD(b)) ? a : b);
    printf("MAX IS %d\n", max);
    printf("A IS %d\n",a);
    printf("B IS %d\n",b);
    return 0;
}