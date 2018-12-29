/// ʵ�ֻ���������� 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Structure.h"

///�ַ�ת��Ϊ����
/// ����ֵ��-1:�������� ; -2: ����̫�� ; -3:�������ֳ�����ĿҪ�󵫿���ִ�� ; else �����ַ������������ 
int str_2_num(char s[])
{
	int len = strlen(s);

	for (int i = 0; i < len; i++) 
	{
		if (isdigit(s[i])) 
			continue;
		else return -1;	// �������� 
	}

	if (len > 8) return -2;	// ����̫��

	int n = 0;
	for (int i = 0; i < len; i++) {
		n = n * 10 + s[i] - '0';
	}
	if (n > 1000000) return -2;// ���ֳ�����Ŀ��Χ
	return n;
}

///  �����д���ļ� 
/// fp�� ָ��д����ļ� 
/// board�� ��Ҫ��ӡ�������վ�
/// flag ֵΪ0�򲻴�ӡ����  
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