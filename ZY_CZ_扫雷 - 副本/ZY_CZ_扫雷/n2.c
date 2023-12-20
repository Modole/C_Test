#include <stdio.h>

int add_l[4];

int prwint_arr(int arr[])
{
    printf("["); // 输出左括号
    for (int i = 3; i >= 0; i--) // 逆序输出 arr 中的每个元素
    {
        printf("0x%02x", arr[i]); // 以十六进制形式输出 arr[i]，并加上 0x 前缀，输出两位，不足的用 0 填充
        if (i > 0) // 如果不是最后一个元素，输出逗号和空格
        {
            printf(", ");
        }
    }
    printf("]\n"); // 输出右括号和换行符
    return 0;
}
#include <stdio.h>

int hewx_array_4()
{
    int num = 0x01020304; // 定义一个整数变量 num
    int* p = &num; // 定义一个整型指针 p，并将 num 的地址赋值给它
    char* q = (char*)p; // 定义一个字符指针 q，并将 p 强制转换为字符指针类型后赋值给它
    char arr[4]; // 定义一个字符数组 arr，用于存储拆分后的字节
    for (int i = 0; i < 4; i++) // 遍历 q 指向的每个字节
    {
        arr[i] = *q; // 将 q 指向的字节赋值给 arr[i]
        q++; // 将 q 指向下一个字节
    }
    for (int i = 0; i < 4; i++) // 遍历 arr 数组
    {
        add_l[i] = arr[i]; // 将 arr[i] 赋值给 add_l[i]
    }
    return 0;
}

void s() {
    hex_array_4();
    print_arr(add_l);
}
