#include <stdio.h>

// 从键盘输入一个字符串，将其中的大写字母换成小写，小写字母换成大写后输出。
int main(int argc, char const *argv[])
{
    char str[50];
    // 获取一行
    gets(str);

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    printf("%s\n", str);
    return 0;
}
