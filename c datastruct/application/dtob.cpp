#include <stdio.h>
#include"scan.h"
#include"to2.h"//���������Ķ�������
int dtob()
{
	int n;
	printf("������һ��������������0�˳�:\n");
	while (scanint( &n) &&n!=0)
	{
		printf("����:%d\n", n);
		printf("���:");
		to2(n);
		printf("\n");
		printf("������һ��������������0�˳�:\n");
	}
	return 0;
}
