#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
int add_l[4];

int cheng = 0;
int sum_cut = 0;
int js = 0;

int a[9][9];

char star[20000];

int print_arr(int arr[])
{
    for (int i = 0; i <= 3; i++) // ������� arr �е�ÿ��Ԫ��
    {
        printf("%02X ", arr[i]); // ��ʮ��������ʽ��� arr[i]�������� 0x ǰ׺�������λ��������� 0 ���
    }
    printf("\t"); // ��������źͻ��з�
    return 0;
}
#include <stdio.h>

int hex_array_4(int num)
{
    if (cheng > 18) {

        return 0;
    }
    int* p = &num; // ����һ������ָ�� p������ num �ĵ�ַ��ֵ����
    char* q = (char*)p; // ����һ���ַ�ָ�� q������ p ǿ��ת��Ϊ�ַ�ָ�����ͺ�ֵ����
    char arr[4]; // ����һ���ַ����� arr�����ڴ洢��ֺ���ֽ�
    for (int i = 0; i < 4; i++) // ���� q ָ���ÿ���ֽ�
    {
        arr[i] = *q; // �� q ָ����ֽڸ�ֵ�� arr[i]
        q++; // �� q ָ����һ���ֽ�
        
        if (arr[i] == 0x10) {
            js++;
            cheng++;
            printf("\n");
        }
        else {

        if (js%2==1) {
        if (arr[i] == 0xFFFFFF8F) {
            printf("* ");
        }
        else {
            printf("%02X ", arr[i]);
        }
        }
        }
    }
    for (int i = 0; i < 4; i++) // ���� arr ����
    {
        add_l[i] = arr[i]; // �� arr[i] ��ֵ�� add_l[i]
    }
    return 0;
}

int main()
{
    
    HWND hwnd;// ���ھ��
    DWORD pid; // ����ID
    HANDLE hProcess; // ���̾��
    long long buffer; // �����������ڴ洢��ȡ������

    // ��ջ�ķ�ʽ��ȡ����������һ�ֽ�һ�ֽڵĶ�ȡ
    // 8-> 4 -> 0 -> c   �����ķ�ʽ��ȡһ��16λ���ڴ�
    int address = 0x01005358; // Ҫ��ȡ���ڴ��ַ
    int end_address = 0x01005688;
    // ��֪��Ϊʲôһ��ֻ��ȡ4λ�ĵ�ַ�����ֻ����4��
    int size = 4 ; // Ҫ��ȡ�����ݴ�С

    hwnd = FindWindowA(NULL, "ɨ��"); // ͨ�����ڱ�����Ҵ��ھ��
    if (hwnd == NULL) // ���û���ҵ������������Ϣ
    {
        printf("�Ҳ�������\n");
        return 1;
    }

    GetWindowThreadProcessId(hwnd, &pid); // ͨ�����ھ����ȡ����ID
    if (pid == 0) // ���û�л�ȡ�������������Ϣ
    {
        printf("��ȡ����IDʧ��\n");
        return 1;
    }

    hProcess = OpenProcess(PROCESS_VM_READ, FALSE, pid); // ͨ������ID�򿪽��̾������Ҫ��ȡȨ��
    if (hProcess == NULL) // ���û�д򿪳ɹ������������Ϣ
    {
        printf("�򿪽���ʧ��\n");
        return 1;
    }
    printf("%d\n",size);
    int count = 0;
    while ((address+=4)<end_address) {
        //printf("0x%x : ", address);
        ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, size, NULL); // ͨ�����̾�����ڴ��ַ�������������ݴ�С����ȡָ�����̵��ڴ�����
        // �����ȡ��������
        hex_array_4(buffer);
       // print_arr(add_l);

    }
    return 0;
}
