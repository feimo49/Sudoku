#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include "Structure.h"
#include "init.h"
#include "generator.h"

int shift[9] = { 0, 6, 3, 8, 5, 2, 7, 4, 1 };//��ƽ����

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

// ����n�������վ�
// n:�������������վֵ�����
// ����ֵ��1:���ɳɹ�; -1:���ɳ���
int generate_sudoku(int n)
{
	FILE *fp;
	fp = fopen("sudoku.txt", "w");
	int count = 0;	// ��������һ�β�������� 
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

		board = backup;	// ��ʼ���� 
		for (int j = 0; j < 6; j++) 
		{
			for (int k = 0; k < 6; k++)
			{
				// 1~3����䷽��1 
				if (count < n) {
					fill(0, j, k, backup, board);
					print(fp, board, count);
					count++;
				}
				else if (count == n) 
				{
					fclose(fp);
					return 1;		// ���ɳɹ�
				}
				else if (count >= n) 
				{
					fclose(fp);
					return -1;	// ����
				}
				// 1~3����䷽��2 
				if (count < n) 
				{
					fill(1, j, k, backup, board);
					print(fp, board, count);
					count++;
				}
				else if (count == n)
				{
					fclose(fp);
					return 1;		// ���ɳɹ� 
				}
				else if (count >= n) 
				{
					fclose(fp);
					return -1;	// ���� 
				}
			}
		}
	}
	fclose(fp);
	return -1;	// ����:����n�Ѿ�����������
}


void generate_ques(int n)
{
	FILE *file1;
	FILE *file2;
	file1 = fopen("sudoku.txt", "r");
	file2 = fopen("sudo.txt", "w");
	int count = 0;
	BOARD board;

	int tmp;
	while (~fscanf(file1, "%d", &tmp))
	{
		board.map[0][0] = tmp;
		for (int j = 1; j < 9; j++)
		{
			fscanf(file1, "%d", &board.map[0][j]);
		}
		for (int i = 1; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fscanf(file1, "%d", &board.map[i][j]);
			}
		}


		int base[9] = { 0,6,12,54,60,66,108,114,120 };
		int add[9] = { 0,2,4,18,20,22,36,38,40 };

		for (int k = 0; k < 9; k++)//ÿ��3*3����Ϳ�2��
		{

			int i, j, pos[2];
			pos[0] = rand() % 9;
			pos[1] = rand() % 9;
			while (pos[0] == pos[1])//��ֹ�ظ�
				pos[1] = rand() % 9;
			for (int t = 0; t < 2; t++)
			{
				int dot;
				dot = base[k] + add[pos[t]];
				i = dot / 18;
				j = dot % 18;
				board.map[i][j] = 0;
			}
		}

		//�Ѿ��Ϳ���18��
		int extra;
		extra = 12 + rand() % 31;
		while (extra--)
		{
			int k = rand() % 81;
			int i = k / 9;
			int j = k % 9;
			j *= 2;
			if (board.map[i][j] != 0)board.map[i][j] = 0;
			else extra++;
		}

		//д�����sudo.txt;
		print(file2, board, count);
		count++;
	}

	fclose(file1);
	fclose(file2);
}