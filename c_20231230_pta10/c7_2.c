#include <stdio.h>
#include <string.h>

// ����һ���ַ���(����50���ַ�)�������ַ�������������
int main(int argc, char const *argv[])
{
    char str[50];
    // ��ȡһ��
    gets(str);

    int start = strlen(str) - 1;
    for (int i = start; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    return 0;
}
