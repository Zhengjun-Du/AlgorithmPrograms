// Triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void GetMinimumPath()
{
	int a[4][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
	int result[4][4];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			result[i][j] = 1e10;
	result[0][0] = a[0][0];

	for(int i = 1; i < 4; i++)
	{
		result[i][0] =  result[i-1][0] +  a[i][0];
		for(int j = 1; j < i; j++)
		{
			result[i][j] =  result[i-1][j-1] +  a[i][j];
			if(result[i][j]  > result[i-1][j] +  a[i][j])
				result[i][j] = result[i-1][j] +  a[i][j];
		}
		result[i][i] =  result[i-1][i-1] +  a[i][i];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	GetMinimumPath();
	return 0;
}

