// 输入一个3位正整数n，
// 分别求出n的个位数字d1十位数字d2和百位数字d3的值。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    int n, d1, d2, d3;
    // printf("请输入一个3位正整数：");
    scanf("%d", &n);

    // 计算结果
    d1 = n % 10;
    d2 = n / 10 % 10;
    d3 = n / 100;

    // 输出结果
    // printf("个位数字：%d\n", d1);
    // printf("十位数字：%d\n", d2);
    // printf("百位数字：%d\n", d3);
    // printf("%d,%d,%d\n", d1, d2, d3);
    // d1=9,d2=9,d3=2
    printf("d1=%d,d2=%d,d3=%d\n", d1, d2, d3);


    return 0;
}
