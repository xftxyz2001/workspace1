// 某电商收费处理是：如果购物费用超过200元(含200元)，包邮，
// 而且，顾客是本店的会员则可以获得购物款打折优惠10%；
// 如果购物费用少于200元，非会员顾客要付快递费10元。
// 编写程序计算顾客的付款情况。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 获取输入
    double cost;
    char is_member;
    scanf("%lf %c", &cost, &is_member);

    // 计算结果
    double discount = 0.1;
    double express_fee = 10;

    double total_cost = cost;
    if (cost >= 200) // 包邮
    {
        // total_cost = cost * (1 - discount);
        if (is_member == 'y') // 会员折扣
        {
            total_cost = total_cost * (1 - discount);
        }
    }
    else if (is_member == 'n') // 非会员支付快递费
    {
        total_cost = total_cost + express_fee;
    }

    // 输出结果
    // 顾客应付款额：270
    printf("顾客应付款额：%.0lf\n", total_cost);

    return 0;
}
