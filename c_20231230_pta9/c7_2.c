#include <stdio.h>
#include <stdlib.h>

// 输入学生人数n，再输入这n个学生的英语成绩（整数），将英语成绩从高到低排序并输出，同时输出最高成绩和最低成绩。
int main(int argc, char const *argv[])
{
    // 第一行输入学生人数n;
    int n;
    scanf("%d", &n);
    // 第二行输入n个学生的英语成绩（整数）。
    int *scores = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
    }

    // 排序
    for (int i = 0; i < n - 1; i++) // 控制轮数
    {
        for (int j = 0; j < n - 1 - i; j++) // 控制比较次数
        {
            if (scores[j] < scores[j + 1])
            {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    // 找到最高分和最低分
    int max = scores[0];
    int min = scores[n - 1];

    // 输出排序后的成绩
    for (int i = 0; i < n; i++)
    {
        printf("%d,", scores[i]);
    }
    printf("\n");

    // 输出最高分和最低分
    // max=98,min=60
    printf("max=%d,min=%d\n", max, min);

    return 0;
}
