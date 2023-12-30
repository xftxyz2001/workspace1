#include <stdio.h>

// 输入一个正整数n，打印输出一个n行“*”组成的等腰三角形。
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) // 控制行数
    {
        for (int j = 1; j <= n - i; j++) // 控制空格数
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) // 控制星号数
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
