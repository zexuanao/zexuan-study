#include<stdio.h>
int scanint(int* input)
{
	while (scanf_s("%d", input) == 0 || getchar() != '\n')
	{
		printf("\n������Υ���ַ������������룺");
		while (getchar() != '\n');
	}
	return 1;
}
int scanfloat(float* input)
{
	while (scanf_s("%f", input) == 0 || getchar() != '\n')
	{
		printf("\n������Υ���ַ������������룺");
		while (getchar() != '\n');
	}
	return 1;
}
int scanchar(char* input)
{
	while (scanf_s("%c", input) == 0 || getchar() != '\n')
	{
		printf("\n������Υ���ַ������������룺");
		while (getchar() != '\n');
	}
	return 1;
}