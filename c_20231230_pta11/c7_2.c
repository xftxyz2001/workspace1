#include <stdio.h>
#include <string.h>

// 编写一个函数，该函数可以计算aaa…aaa(共n个a)的值。
// 在主函数中输入a和n的值，然后调用该函数，将a和n的值传递给该函数，主函数将该函数计算结果输出。
// 提示：该函数是带参函数，参数为a和n，函数返回值为计算结果。
// char *pow(int a, int n)
// {
//     char str[50];
//     for (int i = 0; i < n; i++)
//     {
//         str[i] = a + '0';
//     }
//     str[n] = '\0';
//     return str;
// }
int an(int a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum * 10 + a;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int a, n;
    // a=3,n=4
    scanf("a=%d,n=%d", &a, &n);
    printf("%d\n", an(a, n));
    return 0;
}
