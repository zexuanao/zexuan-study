#include<stdio.h>
void to2(int n)
{
	int yu;
	yu = n % 2;
	if (n >= 2)
		to2(n / 2);
	putchar(yu == 0 ? '0' : ' 1');//������ת��Ϊ�ַ�����Ϊputchar��ʹ��ascll���
}