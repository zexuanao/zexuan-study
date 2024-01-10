#pragma once
#ifndef _SCANF_
#define _SCANF_
#include<stdio.h>
void scanf_d(int* input)
{
	while (scanf_s("%d", input) == 0 || getchar() != '\n')
	{
		printf("\n输入了违法字符，请重新输入：");
		while (getchar() != '\n');
	}
}
void scanf_f(float* input)
{
	while (scanf_s("%f", input) == 0 || getchar() != '\n')
	{
		printf("\n输入了违法字符，请重新输入：");
		while (getchar() != '\n');
	}
}
#endif			