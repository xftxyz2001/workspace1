#include <stdio.h>

// �Ӽ�������һ���ַ����������еĴ�д��ĸ����Сд��Сд��ĸ���ɴ�д�������
int main(int argc, char const *argv[])
{
    char str[50];
    // ��ȡһ��
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
