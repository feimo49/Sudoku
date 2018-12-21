///该头文件用来定义项目中所用到的数据结构
///包括棋盘结构、输出结构
#ifndef __STRUCTURE__
#define __STURCTURE__

// 数独棋盘大小 
#define SIZE 9

// 棋盘结构 
typedef struct {
	int map[SIZE][SIZE];	// 数独盘面
	int col[SIZE];		    // 列
	int row[SIZE];		    // 行  
	int grid[SIZE];		    // 网格 
} BOARD;

//将字符转换为数字 
int str_2_num(char s[]);

// 将输出写入至文件 
void print(FILE* fp, BOARD board, int flag);


#endif