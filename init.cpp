#include "init.h"

int origin[40320][9] = { 0 };// 存放棋盘的全排列（2至8行）
//第1位根据学号要求存放6
int init[9] = { 6, 7, 8, 9, 1, 2, 3, 4, 5 };
int count = 0;

//交换两个数字  
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;	
	b = temp;
}

// 递归求取全排列
void permutation(int offset)
{
	if (offset == 8) 
	{
		for (int i = 0; i < 9; i++)
			origin[count][i] = init[i];
		count++;
		return;
	}
	for (int i = offset; i < 9; i++) 
	{
		swap(init[i], init[offset]);
		permutation(offset + 1);
		swap(init[i], init[offset]);
	}
}

// 初始化全排列数组
void init_origin()
{
	count = 0;
	permutation(1);
}