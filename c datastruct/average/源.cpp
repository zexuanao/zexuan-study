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
		printf("��������Ҫ�������Ŀ��");
		scanf_d(&num);
		point = (float*)malloc(num * sizeof(float));
		head = point;
		for (int i = 0; i < num; i++)
		{
			printf("\n�������%d�����ݣ�", i + 1);
			scanf_f(point + i);
		}
		for (int i = 0; i < num; i++)
		{
			sum += *(head + i);
		}
		printf("ƽ��Ϊ%f\n", sum / num);
		free(point);
		printf("�Ƿ������\n�������������0�ַ�:");
		scanf_f(&con);
	}
	printf("ף����죡");
	return 0;
}