#include <stdio.h>

// ��д�����ж�һ���ַ���������50���ַ����Ƿ��ǻ��ģ����磬��abcdedcba���ǻ��ģ�����abcdedfa�����ǻ��ģ���
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
    // ��ȡһ��
    gets(str);

    if (isPalindrome(str))
    {
        printf("�ǻ���\n");
    }
    else
    {
        printf("���ǻ���\n");
    }

    return 0;
}
