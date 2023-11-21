#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// �����й���ͼ��ȡ15�����ϵĳ�����Ϣ��������������������λ�á�
// ������Щ���е������Ϣ����һ������ͷ���ĵ������С�

// ���ṹ
typedef struct city
{
    char name[20]; // ������
    double lat;    // γ��
    double lon;    // ����
    struct city *next;
} city;

// �������
city *create_city_node(const char *name, double x, double y)
{
    city *p = (city *)malloc(sizeof(city));
    strcpy(p->name, name);
    p->lon = x;
    p->lat = y;
    p->next = NULL;
    return p;
}

// ������������
city *create_city_list()
{
    // char *name[] = {"������", "�����", "�Ϻ���", "������", "��������Ͻ��", "�������Ͻ��", "����н���", "ʯ��ׯ��", "��ɽ��", "�ػʵ���", "������", "��̨��", "������", "�żҿ���", "�е���", "������", "�ȷ���", "��ˮ��", "������", "������", "������", "����", "Ǩ����", "�䰲��", "�Ϲ���"};
    const char *name[] = {"beijing", "tianjin", "shanghai", "chongqing", "beijingshishixiaqu", "tianjinshishixiaqu", "tianjinshijiaoxian", "shijiazhuang", "tangshan", "qinhuangdao", "handan", "xingtai", "baoding", "zhangjiakou", "chengde", "cangzhou", "langfang", "hengshui", "xinji", "jinzhou", "xinle", "zunhua", "qianan", "wuan", "nangong"};
    double x[] = {116.405285, 117.190182, 121.472644, 106.504962, 116.405285, 117.190182, 117.824898, 114.502461, 118.175393, 119.586579, 114.490686, 114.508851, 115.482331, 114.884091, 117.939152, 116.857461, 116.704441, 115.665993, 115.217451, 115.044886, 114.68578, 117.965875, 118.701933, 114.194581, 115.398102};
    double y[] = {39.904989, 39.125596, 31.231706, 29.533155, 39.904989, 39.125596, 39.330613, 38.045474, 39.635113, 39.942531, 36.612273, 37.0682, 38.867657, 40.811901, 40.976204, 38.310582, 39.523927, 37.735097, 37.92904, 38.027478, 38.344768, 40.188616, 40.012108, 36.696115, 37.359668};

    int len = sizeof(x) / sizeof(x[0]);

    city *head = create_city_node("", 0, 0);
    city *p = head;
    for (int i = 0; i < len; i++)
    {
        p->next = create_city_node(name[i], x[i], y[i]);
        p = p->next;
    }
    return head;
}

// ��ӡ��ͷ
void print_city_head()
{
    printf("%s\t\t%s\t\t%s\n", "cityname", "lon", "lat");
}

void _print_city_node(city *p)
{
    printf("%s\t\t%lf\t\t%lf\n", p->name, p->lon, p->lat);
}

// ��ӡ���н��
void print_city_node(city *p)
{
    if (p == NULL)
    {
        printf("city node is empty\n");
        return;
    }
    print_city_head();
    _print_city_node(p);
}

// ��ӡ��������
void print_city_list(city *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("list is empty\n");
        return;
    }

    print_city_head();
    while ((head = head->next) != NULL)
    {
        _print_city_node(head);
    }
}

// ����ĳ����������������λ����Ϣ
city *get_city_info(city *head, char *name)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    while ((head = head->next) != NULL)
    {
        if (strcmp(head->name, name) == 0)
        {
            return head;
        }
    }
    return NULL;
}

// �Ƕ�ת����
double deg2rad(double deg)
{
    const double M_PI = 3.14159265358979323846;
    return deg * (M_PI / 180);
}

// ����������γ�ȣ���������֮��ľ���
// calculateDistance���������ĸ�������
// �ֱ��ǵ�һ�����γ�Ⱥ;��ȣ�lat1��lon1����
// �Լ��ڶ������γ�Ⱥ;��ȣ�lat2��lon2����
// ����������������֮��ľ��루��λ�������
double calculateDistance(double lat1, double lon1, double lat2, double lon2)
{
    double R = 6371.004; // ����뾶����λ������
    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
                   sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    return distance;
}

double distance(city *a, city *b)
{
    // ͨ����γ�ȼ�������֮��ľ���
    double lat1 = a->lat;
    double lon1 = a->lon;

    double lat2 = b->lat;
    double lon2 = b->lon;
    return calculateDistance(lat1, lon1, lat2, lon2);
}

// ���ݳ�����Ϣ����������λ�ã����ɰ뾶ΪR�Ļ�����������λ�ڻ������ڵ�����������Ϣ
city *get_city_in_buffer(city *head, city *center, double R)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    city *result = create_city_node("", 0, 0);
    city *rp = result;

    city *sp = head;
    while ((sp = sp->next) != NULL)
    {
        if (strcmp(sp->name, center->name) == 0)
        {
            continue;
        }

        if (distance(sp, center) <= R)
        {
            rp->next = create_city_node(sp->name, sp->lon, sp->lat);
            rp = rp->next;
        }
    }
    return result;
}

// ����
int main(int argc, char const *argv[])
{
    // ������������
    city *city_list = create_city_list();

    // ��ȡ������Ϣ
    city *city_info = get_city_info(city_list, "beijing");
    if (city_info == NULL)
    {
        printf("city not found\n");
    }
    else
    {
        // ��ӡ������Ϣ
        print_city_node(city_info);

        printf("\n");
        // ��ȡ�������ڵĳ�����Ϣ
        city *city_in_buffer = get_city_in_buffer(city_list, city_info, 100);
        // ��ӡ�������ڵĳ�����Ϣ
        print_city_list(city_in_buffer);
    }

    return 0;
}
