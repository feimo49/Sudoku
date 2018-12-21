#include <stdio.h>
#include "Structure.h"
#include "init.h"
#include "generator.h"

int shift[9] = { 0, 6, 3, 8, 5, 2, 7, 4, 1 };//行平移量

int swaprow_1[2][3] = { {0,1,2}, {0,2,1} };
int swaprow_2[6][3] = { {3,4,5}, {3,5,4}, {4,3,5}, {4,5,3}, {5,3,4}, {5,4,3} };
int swaprow_3[6][3] = { {6,7,8}, {6,8,7}, {7,6,8}, {7,8,6}, {8,6,7}, {8,7,6} };

inline void fill(int m, int n, int l, BOARD &backup, BOARD &board)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++) 
			board.map[i][j] = backup.map[swaprow_1[m][i]][j];
	}
	for (int i = 3; i < 6; i++) 
	{
		for (int j = 0; j < 9; j++) 
			board.map[i][j] = backup.map[swaprow_2[n][i - 3]][j];
	}
	for (int i = 6; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
			board.map[i][j] = backup.map[swaprow_3[l][i - 6]][j];
	}
}

// 生成n个数独终局
// n:需求生成数独终局的数量
// 返回值：1:生成成功; -1:生成出错
int generate_sudoku(int n)
{
	FILE *fp;
	fp = fopen("sudoku.txt", "w");
	int count = 0;	// 计数，第一次不输出空行 
	BOARD board;

	for (int i = 0; i < 40320; i++) 
	{
		BOARD backup;
		for (int k = 0; k < 9; k++)
		{
			backup.map[0][k] = origin[i][k];
			backup.row[k] = 1022;
			backup.col[k] = 1022;
			backup.grid[k] = 1022;
		}

		for (int j = 1; j < 9; j++) 
		{
			for (int k = 0; k < 9; k++) 
				backup.map[j][k] = backup.map[0][(k + shift[j]) % 9];
		}

		board = backup;	// 初始构造 
		for (int j = 0; j < 6; j++) 
		{
			for (int k = 0; k < 6; k++)
			{
				// 1~3行填充方案1 
				if (count < n) {
					fill(0, j, k, backup, board);
					print(fp, board, count);
					count++;
				}
				else if (count == n) 
				{
					fclose(fp);
					return 1;		// 生成成功
				}
				else if (count >= n) 
				{
					fclose(fp);
					return -1;	// 报错
				}
				// 1~3行填充方案2 
				if (count < n) 
				{
					fill(1, j, k, backup, board);
					print(fp, board, count);
					count++;
				}
				else if (count == n)
				{
					fclose(fp);
					return 1;		// 生成成功 
				}
				else if (count >= n) 
				{
					fclose(fp);
					return -1;	// 报错 
				}
			}
		}
	}
	fclose(fp);
	return -1;	// 报错:输入n已经超过最大个数
}