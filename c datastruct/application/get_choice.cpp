#include<stdio.h>
#include"scan.h"
char get_choice(void)
{   
	char ch;
	printf("������ѡ��\n");
	printf("a.��ƽ��ֵ  b.ʮ����ת������  d.������  p.�������  s.�������  q.�˳�\n");
	scanchar(&ch);
	while (ch !='a'&& ch != 'b' && ch!='d' && ch != 'p' && ch != 's' && ch != 'q')
	{
		printf("������a��d��p��s����q\n");
		scanchar(&ch);
	}
	return ch;
}