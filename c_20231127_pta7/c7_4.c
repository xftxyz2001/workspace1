// ��һ����: 2/1��3/2��5/3��8/5......���������ǰn��֮�ͣ�
// n�Ӽ������룬���������λС����
// ��ʾ:��һ��ķ�ĸΪǰһ��ķ��ӣ�����ķ���Ϊǰһ��������ĸ�ĺ͡�

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // ��ȡ����
    int n;
    // printf("������n��ֵ��");
    scanf("%d", &n);

    // ������
    double sum = 0;
    double a = 2, b = 1, t;
    for (int i = 1; i <= n; i++)
    {
        sum += a / b;
        t = a;
        a = a + b;
        b = t;
    }

    // ������
    // printf("���Ϊ��%.2lf\n", sum);
    printf("%.2lf\n", sum);

    return 0;
}
