// ����һ��3λ������n��
// �ֱ����n�ĸ�λ����d1ʮλ����d2�Ͱ�λ����d3��ֵ��

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // ��ȡ����
    int n, d1, d2, d3;
    // printf("������һ��3λ��������");
    scanf("%d", &n);

    // ������
    d1 = n % 10;
    d2 = n / 10 % 10;
    d3 = n / 100;

    // ������
    // printf("��λ���֣�%d\n", d1);
    // printf("ʮλ���֣�%d\n", d2);
    // printf("��λ���֣�%d\n", d3);
    // printf("%d,%d,%d\n", d1, d2, d3);
    // d1=9,d2=9,d3=2
    printf("d1=%d,d2=%d,d3=%d\n", d1, d2, d3);


    return 0;
}
