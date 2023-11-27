// 将26个字母看作一个封闭的环，
// 从键盘上输入任意一个字母和一个正整数n，
// 求该字母后边第n个字母是什么?

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    char c;
    int n;
    // printf("请输入一个字母：");
    // scanf("%c", &c);
    // printf("请输入一个正整数：");
    // scanf("%d", &n);
    scanf("%c %d", &c, &n);

    // 计算结果
    char base = c >= 'a' && c <= 'z' ? 'a' : 'A';
    char offset = c - base;
    char result = (offset + n) % 26 + base;

    // 输出结果
    // printf("结果为：%c\n", result);
    printf("%c", result);

    return 0;
}
