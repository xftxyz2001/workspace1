#include <stdio.h>
#include <string.h>

// �Ӽ�������һ����������ÿλת��ΪӢ�������������ʵ�֣���
int main()
{
    char *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    char str[50];

    // printf("������һ��������");
    scanf("%d", &num);
    sprintf(str, "%d", num); // ������ת��Ϊ�ַ���

    for (int i = 0; i < strlen(str); i++) // �����ַ���
    {
        int index = str[i] - '0';   // ���ַ�ת��Ϊ����
        if (index < 0 || index > 9) // �ж��Ƿ�Ϊ����
        {
            continue;
        }
        printf("%s ", digits[index]);
    }

    return 0;
}