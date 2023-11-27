// 输入一个年份和月份，
// 打印出该月份有多少天（考虑闰年，四年一闰，百年不闰，四百年再闰），
// 用switch语句编程。

#include <stdio.h>

// 获取某年某月的天数
int get_days(int year, int month)
{
    int days = 0;
    switch (month)
    {
    case 1:
        days = 31;
        break;
    case 2:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
        break;
    case 3:
        days = 31;
        break;
    case 4:
        days = 30;
        break;
    case 5:
        days = 31;
        break;
    case 6:
        days = 30;
        break;
    case 7:
        days = 31;
        break;
    case 8:
        days = 31;
        break;
    case 9:
        days = 30;
        break;
    case 10:
        days = 31;
        break;
    case 11:
        days = 30;
        break;
    case 12:
        days = 31;
        break;
    default:
        break;
    }
    return days;
}

int main(int argc, char const *argv[])
{
    // 获取输入
    int year, month;
    // y=2022 m=11
    scanf("y=%d m=%d", &year, &month);

    // 计算结果
    int days = get_days(year, month);

    // 输出结果
    printf("%d天", days);

    return 0;
}
