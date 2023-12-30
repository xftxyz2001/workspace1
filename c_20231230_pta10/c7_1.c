#include <stdio.h>

// ·Ö¶Îº¯Êý
// y={
//     x, x<1
//     2x-1, 1<=x<10
//     3x-11, x>=10
// }
int fx(int x)
{
    if (x < 1)
    {
        return x;
    }
    else if (x >= 1 && x < 10)
    {
        return 2 * x - 1;
    }
    else
    {
        return 3 * x - 11;
    }
}

int main(int argc, char const *argv[])
{
    int x;
    scanf("%d", &x);

    printf("y=%d\n", fx(x));
    return 0;
}
