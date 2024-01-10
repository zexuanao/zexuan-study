#include<stdio.h>
#include"scan.h"
char get_choice(void)
{   
	char ch;
	printf("请输入选项\n");
	printf("a.求平均值  b.十进制转二进制  d.掷骰子  p.动物管理  s.整理句子  q.退出\n");
	scanchar(&ch);
	while (ch !='a'&& ch != 'b' && ch!='d' && ch != 'p' && ch != 's' && ch != 'q')
	{
		printf("请输入a、d、p、s或者q\n");
		scanchar(&ch);
	}
	return ch;
}