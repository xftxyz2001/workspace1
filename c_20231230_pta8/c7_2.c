#include <stdio.h>

// 从键盘输入20个整数，求其最大值、平均值。
int main(int argc, char const *argv[])
{
    int num[20];
    int max = 0;
    int sum = 0;

    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
        if (num[i] > max)
        {
            max = num[i];
        }
    }

    // 前者为最大值，后者为平均值（平均值保留两位小数），最后输出回车换行
    printf("%d %.2f\n", max, (float)sum / 20);
    return 0;
}
