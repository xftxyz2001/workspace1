// 要求读入2个整数A和B，然后输出它们的和。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    int a, b;
    scanf("%d %d", &a, &b);

    // 计算结果
    int sum = a + b;

    // 输出结果
    printf("%d", sum);

    return 0;
}
