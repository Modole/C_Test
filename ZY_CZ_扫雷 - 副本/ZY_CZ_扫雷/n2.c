#include <stdio.h>

int add_l[4];

int prwint_arr(int arr[])
{
    printf("["); // ���������
    for (int i = 3; i >= 0; i--) // ������� arr �е�ÿ��Ԫ��
    {
        printf("0x%02x", arr[i]); // ��ʮ��������ʽ��� arr[i]�������� 0x ǰ׺�������λ��������� 0 ���
        if (i > 0) // ����������һ��Ԫ�أ�������źͿո�
        {
            printf(", ");
        }
    }
    printf("]\n"); // ��������źͻ��з�
    return 0;
}
#include <stdio.h>

int hewx_array_4()
{
    int num = 0x01020304; // ����һ���������� num
    int* p = &num; // ����һ������ָ�� p������ num �ĵ�ַ��ֵ����
    char* q = (char*)p; // ����һ���ַ�ָ�� q������ p ǿ��ת��Ϊ�ַ�ָ�����ͺ�ֵ����
    char arr[4]; // ����һ���ַ����� arr�����ڴ洢��ֺ���ֽ�
    for (int i = 0; i < 4; i++) // ���� q ָ���ÿ���ֽ�
    {
        arr[i] = *q; // �� q ָ����ֽڸ�ֵ�� arr[i]
        q++; // �� q ָ����һ���ֽ�
    }
    for (int i = 0; i < 4; i++) // ���� arr ����
    {
        add_l[i] = arr[i]; // �� arr[i] ��ֵ�� add_l[i]
    }
    return 0;
}

void s() {
    hex_array_4();
    print_arr(add_l);
}
