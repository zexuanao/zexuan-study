#include<stdio.h>
#include"average.h"
#include"get_choice.h"
#include"dice_roll.h"
#include"sort_str.h"
#include"dtob.h"
#include"petclub.h"
int main(void)
{
	int choice;
	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case'a':average();
		break;
		case'b':dtob();
	    break;
		case'd':dice_roll();
		break;
		case's':sort_str();
		break;
		case'p':petclub();
		break;
		default:printf("发生错误\n");
		break;
		}
	}
	printf("再见！\n");
	return 0;
}
