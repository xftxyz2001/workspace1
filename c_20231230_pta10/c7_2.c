#include <stdio.h>
#include <string.h>

// 输入一个字符串(少于50个字符)，将该字符串逆序后输出。
int main(int argc, char const *argv[])
{
    char str[50];
    // 获取一行
    gets(str);

    int start = strlen(str) - 1;
    for (int i = start; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    return 0;
}
