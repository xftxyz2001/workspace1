#include <stdio.h>

// 输入一个数字字符串，并将其存放在一个字符数组中，然后将该字符串转换为其对应整数输出。
int str_to_int(char str[])
{
    int i = 0, num = 0;
    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

int main()
{
    char numStr[50];
    int num = 0;

    // printf("请输入一个数字字符串：");
    scanf("%s", numStr);

    // 将数字字符串转换为整数
    num = str_to_int(numStr);

    printf("%d\n", num);

    return 0;
}

int main2(int argc, char const *argv[])
{
    char numStr[50];
    int num = 0;
    // printf("请输入一个数字字符串：");
    scanf("%s", numStr);
    // 将数字字符串转换为整数
    sscanf(numStr, "%d", &num);
    printf("%d\n", num);

    return 0;
}

int main1(int argc, char const *argv[])
{
    int num = 0;
    scanf("%d", &num);
    printf("%d\n", num);

    return 0;
}
