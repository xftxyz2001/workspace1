// ��26����ĸ����һ����յĻ���
// �Ӽ�������������һ����ĸ��һ��������n��
// �����ĸ��ߵ�n����ĸ��ʲô?

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // ��ȡ����
    char c;
    int n;
    // printf("������һ����ĸ��");
    // scanf("%c", &c);
    // printf("������һ����������");
    // scanf("%d", &n);
    scanf("%c %d", &c, &n);

    // ������
    char base = c >= 'a' && c <= 'z' ? 'a' : 'A';
    char offset = c - base;
    char result = (offset + n) % 26 + base;

    // ������
    // printf("���Ϊ��%c\n", result);
    printf("%c", result);

    return 0;
}
