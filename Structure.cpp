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
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[0][0], ' ', board.map[0][1], ' ', board.map[0][2], ' ', board.map[0][3], ' ', board.map[0][4], ' ', board.map[0][5], ' ', board.map[0][6], ' ', board.map[0][7], ' ', board.map[0][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[1][0], ' ', board.map[1][1], ' ', board.map[1][2], ' ', board.map[1][3], ' ', board.map[1][4], ' ', board.map[1][5], ' ', board.map[1][6], ' ', board.map[1][7], ' ', board.map[1][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[2][0], ' ', board.map[2][1], ' ', board.map[2][2], ' ', board.map[2][3], ' ', board.map[2][4], ' ', board.map[2][5], ' ', board.map[2][6], ' ', board.map[2][7], ' ', board.map[2][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[3][0], ' ', board.map[3][1], ' ', board.map[3][2], ' ', board.map[3][3], ' ', board.map[3][4], ' ', board.map[3][5], ' ', board.map[3][6], ' ', board.map[3][7], ' ', board.map[3][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[4][0], ' ', board.map[4][1], ' ', board.map[4][2], ' ', board.map[4][3], ' ', board.map[4][4], ' ', board.map[4][5], ' ', board.map[4][6], ' ', board.map[4][7], ' ', board.map[4][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[5][0], ' ', board.map[5][1], ' ', board.map[5][2], ' ', board.map[5][3], ' ', board.map[5][4], ' ', board.map[5][5], ' ', board.map[5][6], ' ', board.map[5][7], ' ', board.map[5][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[6][0], ' ', board.map[6][1], ' ', board.map[6][2], ' ', board.map[6][3], ' ', board.map[6][4], ' ', board.map[6][5], ' ', board.map[6][6], ' ', board.map[6][7], ' ', board.map[6][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[7][0], ' ', board.map[7][1], ' ', board.map[7][2], ' ', board.map[7][3], ' ', board.map[7][4], ' ', board.map[7][5], ' ', board.map[7][6], ' ', board.map[7][7], ' ', board.map[7][8]);
	fprintf(fp, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n", board.map[8][0], ' ', board.map[8][1], ' ', board.map[8][2], ' ', board.map[8][3], ' ', board.map[8][4], ' ', board.map[8][5], ' ', board.map[8][6], ' ', board.map[8][7], ' ', board.map[8][8]);
}