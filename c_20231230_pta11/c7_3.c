#include <stdio.h>
#include <math.h>

// ��д�����ж�ĳһ�����Ƿ�Ϊ������
// Ҫ��
// (1)���ж�������Ϊ�����������롣
// (2)�����ķ���ֵΪ0��1��0��ʾ���ǣ�1 ��ʾ�ǡ�

// ������������1��������a��b����a<b����дһ��ʹ�øú����ĳ���ʵ�ֶ�a��b�����������������������a��b���жϣ���
int isPrime(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    int sqrtNum = sqrt(num);
    for (int i = 5; i <= sqrtNum; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int a, b;
    // 3 30
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}
