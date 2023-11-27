// 求ax^2+bx+c=0方程的根。a,b,c由键盘输入，设b^2-4ac>0

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

    // 获取输入
    double a, b, c;
    scanf("a=%lf b=%lf c=%lf", &a, &b, &c);

    // 计算结果
    double x1, x2;
    double d = b * b - 4 * a * c;
    // x1是加开方的根，x2是减开方的根，顺序不要乱！
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);

    // 输出结果
    // x1=0.0 x2=-0.8
    printf("x1=%.1lf x2=%.1lf\n", x1, x2);

    return 0;
}
