#include <stdio.h>

// ����һ��������n����ӡ���һ��n�С�*����ɵĵ��������Ρ�
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) // ��������
    {
        for (int j = 1; j <= n - i; j++) // ���ƿո���
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) // �����Ǻ���
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
