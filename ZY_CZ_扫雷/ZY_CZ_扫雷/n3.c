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
    for (int i = 0; i <= 3; i++) // 逆序输出 arr 中的每个元素
    {
        printf("%02X ", arr[i]); // 以十六进制形式输出 arr[i]，并加上 0x 前缀，输出两位，不足的用 0 填充
    }
    printf("\t"); // 输出右括号和换行符
    return 0;
}
#include <stdio.h>

int hex_array_4(int num)
{
    if (cheng > 18) {

        return 0;
    }
    int* p = &num; // 定义一个整型指针 p，并将 num 的地址赋值给它
    char* q = (char*)p; // 定义一个字符指针 q，并将 p 强制转换为字符指针类型后赋值给它
    char arr[4]; // 定义一个字符数组 arr，用于存储拆分后的字节
    for (int i = 0; i < 4; i++) // 遍历 q 指向的每个字节
    {
        arr[i] = *q; // 将 q 指向的字节赋值给 arr[i]
        q++; // 将 q 指向下一个字节
        
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
    for (int i = 0; i < 4; i++) // 遍历 arr 数组
    {
        add_l[i] = arr[i]; // 将 arr[i] 赋值给 add_l[i]
    }
    return 0;
}

int main()
{
    
    HWND hwnd;// 窗口句柄
    DWORD pid; // 进程ID
    HANDLE hProcess; // 进程句柄
    long long buffer; // 缓冲区，用于存储读取的数据

    // 以栈的方式读取，从右往左，一字节一字节的读取
    // 8-> 4 -> 0 -> c   这样的方式读取一个16位的内存
    int address = 0x01005358; // 要读取的内存地址
    int end_address = 0x01005688;
    // 不知道为什么一次只读取4位的地址，多大都只返回4个
    int size = 4 ; // 要读取的数据大小

    hwnd = FindWindowA(NULL, "扫雷"); // 通过窗口标题查找窗口句柄
    if (hwnd == NULL) // 如果没有找到，输出错误信息
    {
        printf("找不到窗口\n");
        return 1;
    }

    GetWindowThreadProcessId(hwnd, &pid); // 通过窗口句柄获取进程ID
    if (pid == 0) // 如果没有获取到，输出错误信息
    {
        printf("获取进程ID失败\n");
        return 1;
    }

    hProcess = OpenProcess(PROCESS_VM_READ, FALSE, pid); // 通过进程ID打开进程句柄，需要读取权限
    if (hProcess == NULL) // 如果没有打开成功，输出错误信息
    {
        printf("打开进程失败\n");
        return 1;
    }
    printf("%d\n",size);
    int count = 0;
    while ((address+=4)<end_address) {
        //printf("0x%x : ", address);
        ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, size, NULL); // 通过进程句柄，内存地址，缓冲区，数据大小，读取指定进程的内存数据
        // 输出读取到的数据
        hex_array_4(buffer);
       // print_arr(add_l);

    }
    return 0;
}
