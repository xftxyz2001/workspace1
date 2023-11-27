// ����һ����ݺ��·ݣ�
// ��ӡ�����·��ж����죨�������꣬����һ�򣬰��겻���İ������򣩣�
// ��switch����̡�

#include <stdio.h>

// ��ȡĳ��ĳ�µ�����
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
    // ��ȡ����
    int year, month;
    // y=2022 m=11
    scanf("y=%d m=%d", &year, &month);

    // ������
    int days = get_days(year, month);

    // ������
    printf("%d��", days);

    return 0;
}
