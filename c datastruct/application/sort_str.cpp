#include <stdio.h>
#include <string.h>
#include"s_gets.h"
#define SIZE 81
#define LIM 20
int sort_str(void)
{
	char input[LIM][SIZE];
	char* ptstr[LIM];
	int ct = 0;
	int k;
	char* temp;
	int top, seek;
	printf("请输入最多%d行。\n", LIM);
	printf("如果需要停止，请在一行开始输入\\n\n");
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];;
		ct++;
	}
	for (top = 0; top < ct - 1; top++)
		for (seek = top + 1; seek < ct; seek++)
			if (strcmp(ptstr[top], ptstr[seek]) > 0)
			{
				temp = ptstr[top];
				ptstr[top] = ptstr[seek];
				ptstr[seek] = temp;
			}
	puts("\n整理后:\n");
	for (k = 0; k < ct; k++)
		puts(ptstr[k]);

	return 0;
}

