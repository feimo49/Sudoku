///��ͷ�ļ�����������Ŀ�����õ������ݽṹ
///�������̽ṹ������ṹ
#ifndef __STRUCTURE__
#define __STURCTURE__

// �������̴�С 
#define SIZE 9

// ���̽ṹ 
typedef struct {
	int map[SIZE][SIZE];	// ��������
	int col[SIZE];		    // ��
	int row[SIZE];		    // ��  
	int grid[SIZE];		    // ���� 
} BOARD;

//���ַ�ת��Ϊ���� 
int str_2_num(char s[]);

// �����д�����ļ� 
void print(FILE* fp, BOARD board, int flag);


#endif