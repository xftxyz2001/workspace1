#include <stdio.h>

// �Ӽ�������20���������������ֵ��ƽ��ֵ��
int main(int argc, char const *argv[])
{
    int num[20];
    int max = 0;
    int sum = 0;

    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
        if (num[i] > max)
        {
            max = num[i];
        }
    }

    // ǰ��Ϊ���ֵ������Ϊƽ��ֵ��ƽ��ֵ������λС�������������س�����
    printf("%d %.2f\n", max, (float)sum / 20);
    return 0;
}
