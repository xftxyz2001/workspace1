#include <stdio.h>

// ����һ���ַ����ҳ����д�д��ĸ��Сд��ĸ���ո����ּ������ַ����ж��١�
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

    // ��д��ĸ:2 Сд��ĸ:6 �ո�:2 ����:3 �����ַ�:2
    printf("��д��ĸ:%d Сд��ĸ:%d �ո�:%d ����:%d �����ַ�:%d\n", upper, lower, space, digit, other);
    return 0;
}
