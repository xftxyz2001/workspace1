// 从键盘上输入3个整数，求最大值并将其输出。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    int a, b, c, max;
    scanf("%d,%d,%d", &a, &b, &c);

    // 计算结果
    max = a > b ? a : b;
    max = max > c ? max : c;

    // 输出结果
    printf("%d", max);

    return 0;
}
