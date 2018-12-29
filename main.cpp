#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Structure.h"
#include"init.h"
#include"generator.h"
#include"solver.h"

///本cpp为主函数，用以实现①向文件写入1~1e6个终局
///                      ②从指定路径文件中读取数独题目并解数独

int main(int argc,char* argv[])
{
	if (strcmp(argv[1], "-c") == 0)
	{
		int n = str_2_num(argv[2]);
	    if (n == 0||n==-1)
			printf("\nWrong: Please input correctly!\n");
		else if (n == -2)
			printf("\nWrong: The number you entered exceeds the maximun range!\n");
		else
		{
	     	if (origin[0][0] == 0) init_origin();
			int examine = generate_sudoku(n);

			if (examine == -1)printf("\nProgram Execution Error: Wrong on creation of the end of sudoku.\n");
			else printf("Completed!\n");
		}
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		generate_ques(100);
		FILE *fp;
		fp = fopen(argv[2], "r");
		if (fp == NULL) 
			printf("\nWrong: File open failed.\n");
		solve_sudoku(fp);
		printf("Successfully solved!\n");
	}

	system("pause");
	return 0;
}