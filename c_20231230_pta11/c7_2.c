#include <stdio.h>
#include <string.h>

// ��дһ���������ú������Լ���aaa��aaa(��n��a)��ֵ��
// ��������������a��n��ֵ��Ȼ����øú�������a��n��ֵ���ݸ��ú��������������ú��������������
// ��ʾ���ú����Ǵ��κ���������Ϊa��n����������ֵΪ��������
// char *pow(int a, int n)
// {
//     char str[50];
//     for (int i = 0; i < n; i++)
//     {
//         str[i] = a + '0';
//     }
//     str[n] = '\0';
//     return str;
// }
int an(int a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum * 10 + a;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int a, n;
    // a=3,n=4
    scanf("a=%d,n=%d", &a, &n);
    printf("%d\n", an(a, n));
    return 0;
}
