#include<stdio.h>
#include<stdlib.h>
#include"scan.h"
void average(void)
{
	int num = 0;
	float sum = 0;
	float* point;
	float* head;
	float con = 1;
	while (con)
	{
		printf("��������Ҫ�������Ŀ��");
		scanint(&num);
		point = (float*)malloc(num * sizeof(float));
		head = point;
		for (int i = 0; i < num; i++)
		{
			printf("\n�������%d�����ݣ�", i + 1);
			scanfloat(point + i);
		}
		for (int i = 0; i < num; i++)
		{
			sum += *(head + i);
		}
		printf("ƽ��Ϊ%f\n", sum / num);
		free(point);
		printf("�Ƿ������\n�������������0�ַ�:");
		scanfloat(&con);
	}
}