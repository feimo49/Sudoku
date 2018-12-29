/// 实现基本输入输出 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Structure.h"

///字符转换为数字
/// 返回值：-1:不是数字 ; -2: 数字太大 ; -3:输入数字超过题目要求但可以执行 ; else 返回字符串代表的数字 
int str_2_num(char s[])
{
	int len = strlen(s);

	for (int i = 0; i < len; i++) 
	{
		if (isdigit(s[i])) 
			continue;
		else return -1;	// 不是数字 
	}

	if (len > 8) return -2;	// 数字太大

	int n = 0;
	for (int i = 0; i < len; i++) {
		n = n * 10 + s[i] - '0';
	}
	if (n > 1000000) return -2;// 数字超出题目范围
	return n;
}

///  将输出写入文件 
/// fp： 指向写入的文件 
/// board： 需要打印的数独终局
/// flag 值为0则不打印空行  
void print(FILE* fp, BOARD board, int flag)
{
	if (flag != 0)
		fputc('\n', fp);
	char str[163];
	for (int i = 0; i < 162; i++)
	{
		int t = i % 18;
		if (t == 17)str[i] = '\n';
		else if (i % 2 == 1)str[i] = ' ';
		else str[i] = board.map[i / 18][t / 2]+'0';
	}
	str[162] = '\0';
	fputs(str, fp);
}