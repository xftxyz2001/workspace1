// ��ax^2+bx+c=0���̵ĸ���a,b,c�ɼ������룬��b^2-4ac>0

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

    // ��ȡ����
    double a, b, c;
    scanf("a=%lf b=%lf c=%lf", &a, &b, &c);

    // ������
    double x1, x2;
    double d = b * b - 4 * a * c;
    // x1�Ǽӿ����ĸ���x2�Ǽ������ĸ���˳��Ҫ�ң�
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);

    // ������
    // x1=0.0 x2=-0.8
    printf("x1=%.1lf x2=%.1lf\n", x1, x2);

    return 0;
}
