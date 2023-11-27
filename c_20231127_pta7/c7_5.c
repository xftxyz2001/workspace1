// 输入一个正整数n，打印输出一个n行n列“*”组成的正方形。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    int n;
    scanf("%d", &n);

    // 打印结果
    for (int i = 0; i < n; i++)
    {
        // 打印一行
        for (int j = 0; j < n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
