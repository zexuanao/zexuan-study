#define X  )*2+1
#define _  )*2
#define s  ((((((((((((((((0 
static unsigned short stopwatch[] = 
{
s _ _ _ _ _ X X X X X _ _ _ X X _,
s _ _ _ X X X X X X X X X _ X X X,
s _ _ X X X _ _ _ _ _ X X X _ X X,
s _ X X _ _ _ _ _ _ _ _ _ X X _ _,
s _ X X _ _ _ _ _ _ _ _ _ X X _ _,
s X X _ _ _ _ _ _ _ _ _ _ _ X X _,
s X X _ _ _ _ _ _ _ _ _ _ _ X X _,
s X X _ X X X X X _ _ _ _ _ X X _,
s X X _ _ _ _ _ X _ _ _ _ _ X X _,
s X X _ _ _ _ _ X _ _ _ _ _ X X _,
s _ X X _ _ _ _ X _ _ _ _ X X _ _,
s _ X X _ _ _ _ X _ _ _ _ X X _ _,
s _ _ X X X _ _ _ _ _ X X X _ _ _,
s _ _ _ X X X X X X X X X _ _ _ _,
s _ _ _ _ _ X X X X X _ _ _ _ _ _,
s _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
};
int scanint();
void to2(int n);
#include<stdio.h>
int main(){
     for(int i=0;i<16;i++)
	   {
       to2(stopwatch[i]);
	   printf("\n");
	   }
}
int scanint(int* input)
{
	while (scanf("%d", input) == 0 || getchar() != '\n')
	{
		printf("\n输入了违法字符,请重新输入:");
		while (getchar() != '\n');
	}
	return 1;
}
void to2(int n)
{
	int yu;
	yu = n % 2;
	if (n >= 2)
		to2(n / 2);
	putchar(yu == 0 ? '0' : ' 1');//将数字转化为字符，因为putchar是使用ascll码的
}

