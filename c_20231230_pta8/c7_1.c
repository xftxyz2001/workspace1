#include <stdio.h>
#include <string.h>

// 从键盘输入一个整数，把每位转换为英文输出（用数组实现）。
int main()
{
    char *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    char str[50];

    // printf("请输入一个整数：");
    scanf("%d", &num);
    sprintf(str, "%d", num); // 将整数转换为字符串

    for (int i = 0; i < strlen(str); i++) // 遍历字符串
    {
        int index = str[i] - '0';   // 将字符转换为整数
        if (index < 0 || index > 9) // 判断是否为数字
        {
            continue;
        }
        printf("%s ", digits[index]);
    }

    return 0;
}