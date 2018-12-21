#include "init.h"

int origin[40320][9] = { 0 };// ������̵�ȫ���У�2��8�У�
//��1λ����ѧ��Ҫ����6
int init[9] = { 6, 7, 8, 9, 1, 2, 3, 4, 5 };
int count = 0;

//������������  
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;	
	b = temp;
}

// �ݹ���ȡȫ����
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

// ��ʼ��ȫ��������
void init_origin()
{
	count = 0;
	permutation(1);
}