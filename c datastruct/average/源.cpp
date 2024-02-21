#include<stdio.h>
#include<stdlib.h>
#include"scanf.h"
int main()
{
	int num = 0;
	float sum = 0;
	float* point;
	float* head;
	float con = 1;
	while (con)
	{
		printf("请输入你要计算的数目：");
		scanf_d(&num);
		point = (float*)malloc(num * sizeof(float));
		head = point;
		for (int i = 0; i < num; i++)
		{
			printf("\n请输入第%d个数据：", i + 1);
			scanf_f(point + i);
		}
		for (int i = 0; i < num; i++)
		{
			sum += *(head + i);
		}
		printf("平均为%f\n", sum / num);
		free(point);
		printf("是否继续？\n若继续请输入非0字符:");
		scanf_f(&con);
	}
	printf("祝您愉快！");
	return 0;
}