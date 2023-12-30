#include <stdio.h>
#include <math.h>

// 编写函数判断某一数字是否为素数。
// 要求：
// (1)被判断数字作为函数参数传入。
// (2)函数的返回值为0或1。0表示不是，1 表示是。

// 输入两个大于1的正整数a和b，且a<b，编写一个使用该函数的程序，实现对a、b间所有素数的输出（包含对a和b的判断）。
int isPrime(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    int sqrtNum = sqrt(num);
    for (int i = 5; i <= sqrtNum; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int a, b;
    // 3 30
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}
