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
	printf("请输入每个骰子的面数,输入0退出\n");
	while (scanint(&sides) && sides > 0)
	{
		total = 0;
		printf("几个骰子？\n");
		scanint(&dice);
		if (sides < 2)
		{
			printf("至少有两个面\n");
			return -2;
		}
		if (dice < 1)
		{
			printf("至少骰一个骰子\n");
			return -1;
		}
		for (d = 0; d < dice; d++)
			total += rollem(sides);
		printf("你使用%d个%d面骰子投掷出了%d\n", dice, sides, total);
		
		printf("请输入每个骰子的面数,输入0退出\n");
	}
	printf("祝你好运！\n");
	return 0;
}