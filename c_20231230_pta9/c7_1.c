#include <stdio.h>

// 输入一行字符，找出其中大写字母、小写字母、空格、数字及其他字符各有多少。
int main(int argc, char const *argv[])
{
    char c;
    int upper = 0, lower = 0, space = 0, digit = 0, other = 0;

    while ((c = getchar()) != '\n')
    {
        if (c >= 'A' && c <= 'Z')
        {
            upper++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            lower++;
        }
        else if (c == ' ')
        {
            space++;
        }
        else if (c >= '0' && c <= '9')
        {
            digit++;
        }
        else
        {
            other++;
        }
    }

    // 大写字母:2 小写字母:6 空格:2 数字:3 其它字符:2
    printf("大写字母:%d 小写字母:%d 空格:%d 数字:%d 其它字符:%d\n", upper, lower, space, digit, other);
    return 0;
}
