#include <stdio.h>
#include <Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\"/entry\"mainCRTStartup\"");//Ԥ���� 

int main() {
	int a = 10;
	char* b = &a;
	*b = 20000;
	printf("%d",a);
	return 0;
}

