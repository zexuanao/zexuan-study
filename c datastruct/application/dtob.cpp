#include <stdio.h>
#include"scan.h"
#include"to2.h"//输出这个数的二进制数
int dtob()
{
	int n;
	printf("请输入一个整数，或输入0退出:\n");
	while (scanint( &n) &&n!=0)
	{
		printf("输入:%d\n", n);
		printf("输出:");
		to2(n);
		printf("\n");
		printf("请输入一个整数，或输入0退出:\n");
	}
	return 0;
}
