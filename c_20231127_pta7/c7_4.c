// 有一序列: 2/1，3/2，5/3，8/5......，求该序列前n项之和，
// n从键盘输入，结果保留两位小数。
// 提示:后一项的分母为前一项的分子，后项的分子为前一项分子与分母的和。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    int n;
    // printf("请输入n的值：");
    scanf("%d", &n);

    // 计算结果
    double sum = 0;
    double a = 2, b = 1, t;
    for (int i = 1; i <= n; i++)
    {
        sum += a / b;
        t = a;
        a = a + b;
        b = t;
    }

    // 输出结果
    // printf("结果为：%.2lf\n", sum);
    printf("%.2lf\n", sum);

    return 0;
}
