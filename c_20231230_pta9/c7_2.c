#include <stdio.h>
#include <stdlib.h>

// ����ѧ������n����������n��ѧ����Ӣ��ɼ�������������Ӣ��ɼ��Ӹߵ������������ͬʱ�����߳ɼ�����ͳɼ���
int main(int argc, char const *argv[])
{
    // ��һ������ѧ������n;
    int n;
    scanf("%d", &n);
    // �ڶ�������n��ѧ����Ӣ��ɼ�����������
    int *scores = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
    }

    // ����
    for (int i = 0; i < n - 1; i++) // ��������
    {
        for (int j = 0; j < n - 1 - i; j++) // ���ƱȽϴ���
        {
            if (scores[j] < scores[j + 1])
            {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    // �ҵ���߷ֺ���ͷ�
    int max = scores[0];
    int min = scores[n - 1];

    // ��������ĳɼ�
    for (int i = 0; i < n; i++)
    {
        printf("%d,", scores[i]);
    }
    printf("\n");

    // �����߷ֺ���ͷ�
    // max=98,min=60
    printf("max=%d,min=%d\n", max, min);

    return 0;
}
