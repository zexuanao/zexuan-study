#pragma once
#ifndef _SCANF_
#define _SCANF_
#include<stdio.h>
void scanf_d(int* input)
{
	while (scanf_s("%d", input) == 0 || getchar() != '\n')
	{
		printf("\n������Υ���ַ������������룺");
		while (getchar() != '\n');
	}
}
void scanf_f(float* input)
{
	while (scanf_s("%f", input) == 0 || getchar() != '\n')
	{
		printf("\n������Υ���ַ������������룺");
		while (getchar() != '\n');
	}
}
#endif			