#include <stdio.h>

// ����һ�������ַ���������������һ���ַ������У�Ȼ�󽫸��ַ���ת��Ϊ���Ӧ���������
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

    // printf("������һ�������ַ�����");
    scanf("%s", numStr);

    // �������ַ���ת��Ϊ����
    num = str_to_int(numStr);

    printf("%d\n", num);

    return 0;
}

int main2(int argc, char const *argv[])
{
    char numStr[50];
    int num = 0;
    // printf("������һ�������ַ�����");
    scanf("%s", numStr);
    // �������ַ���ת��Ϊ����
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
