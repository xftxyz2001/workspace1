// ĳ�����շѴ����ǣ����������ó���200Ԫ(��200Ԫ)�����ʣ�
// ���ң��˿��Ǳ���Ļ�Ա����Ի�ù��������Ż�10%��
// ��������������200Ԫ���ǻ�Ա�˿�Ҫ����ݷ�10Ԫ��
// ��д�������˿͵ĸ��������

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // ��ȡ����
    double cost;
    char is_member;
    scanf("%lf %c", &cost, &is_member);

    // ������
    double discount = 0.1;
    double express_fee = 10;

    double total_cost = cost;
    if (cost >= 200) // ����
    {
        // total_cost = cost * (1 - discount);
        if (is_member == 'y') // ��Ա�ۿ�
        {
            total_cost = total_cost * (1 - discount);
        }
    }
    else if (is_member == 'n') // �ǻ�Ա֧����ݷ�
    {
        total_cost = total_cost + express_fee;
    }

    // ������
    // �˿�Ӧ����270
    printf("�˿�Ӧ����%.0lf\n", total_cost);

    return 0;
}
