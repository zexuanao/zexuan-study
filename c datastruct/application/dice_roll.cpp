#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"scan.h"
#include"rollem.h"

int dice_roll(void)
{
	int dice;
	int sides;
	int d;
	int total = 0;
	srand((unsigned int)time(0));
	printf("������ÿ�����ӵ�����,����0�˳�\n");
	while (scanint(&sides) && sides > 0)
	{
		total = 0;
		printf("�������ӣ�\n");
		scanint(&dice);
		if (sides < 2)
		{
			printf("������������\n");
			return -2;
		}
		if (dice < 1)
		{
			printf("������һ������\n");
			return -1;
		}
		for (d = 0; d < dice; d++)
			total += rollem(sides);
		printf("��ʹ��%d��%d������Ͷ������%d\n", dice, sides, total);
		
		printf("������ÿ�����ӵ�����,����0�˳�\n");
	}
	printf("ף����ˣ�\n");
	return 0;
}