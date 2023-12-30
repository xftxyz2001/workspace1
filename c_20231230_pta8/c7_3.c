#include <stdio.h>

// ��д������������������m��n���������Լ������С��������
int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d,%d", &m, &n);

    int max = m > n ? m : n;
    int min = m < n ? m : n;

    int gcd = 1;
    int lcm = m * n;

    for (int i = 2; i <= min; i++)
    {
        if (m % i == 0 && n % i == 0)
        {
            gcd = i;
        }
    }

    for (int i = max; i <= lcm; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            lcm = i;
            break;
        }
    }

    printf("%d,%d\n", gcd, lcm);

    return 0;
}
