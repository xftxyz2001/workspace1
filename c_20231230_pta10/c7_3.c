#include <stdio.h>

// 编写程序，判断一个字符串（少于50个字符）是否是回文（例如，”abcdedcba”是回文，而”abcdedfa”不是回文）。
int isPalindrome(char str[])
{
    int right = strlen(str) - 1;
    int left = 0;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    char str[50];
    // 获取一行
    gets(str);

    if (isPalindrome(str))
    {
        printf("是回文\n");
    }
    else
    {
        printf("不是回文\n");
    }

    return 0;
}
