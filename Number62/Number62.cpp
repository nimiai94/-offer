// Number62.cpp : 定义控制台应用程序的入口点。
//求两个字符串的最长公共子序列,并输出

#include "stdafx.h"
#include <cstring>

int LCS(char* str1,char* str2,int** b)
{
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	//二维数组分配地址空间
	int** data=new int*[length1+1];
	for (int i = 0; i < length1 + 1; i++)
		data[i] = new int[length2 + 1];
	//二维数组第0列和第0行都初始化为0
	for (int i = 0; i < length1 + 1; i++)
		data[i][0] = 0;
	for (int i = 0; i < length2 + 1; i++)
		data[0][i] = 0;

	for (int i = 1; i < length1 + 1; i++)
	{
		for (int j = 1; j < length2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				data[i][j] = data[i - 1][j - 1] + 1;
				b[i][j] = 0;

			}
			else if (data[i - 1][j] > data[i][j - 1])
			{
				data[i][j] = data[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				data[i][j] = data[i][j-1];
				b[i][j] = -1;
			}
		}
	}
	int len = data[length1][length2];
	for (int i = 0; i < length1 + 1; i++)
		delete[] data[i];
	delete[] data;
	return len;
}
void PrintLCS(int** b, char* str1, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		PrintLCS(b, str1, i - 1, j - 1);
		printf("%c", str1[i - 1]);
	}
	else if (b[i][j] == 1)
	{
		PrintLCS(b, str1, i - 1, j);
	}
	else
		PrintLCS(b, str1, i, j - 1);
}
int main()
{
	char str1[100], str2[100];
	printf("str1：");
	gets_s(str1,100);
	printf("str2:");
	gets_s(str2,100);
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	int** b = new int*[length1 + 1];
	for (int i = 0; i < length1 + 1; i++)
		b[i] = new int[length2 + 1];

	int len = LCS(str1, str2, b);
	PrintLCS(b, str1, length1, length2);
	for (int i = 0; i < length1 + 1; i++)
		delete[] b[i];
	delete[] b;

	getchar();
    return 0;
}

