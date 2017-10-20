// test_PackageAnswer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

int W = 10;  
int N = 5;
int weight[5] = {4, 5, 6, 2, 2};  
int value[5] = {6, 4, 5, 3, 6};  
int result[5][11];

int GetZeroOnePackage(int i, int j)
{
	if(j < weight[i] || i < 0)
		return 0;
	if(result[i][j] != -1)
		return result[i][j];

	int withCurrObject = GetZeroOnePackage(i-1,j-weight[i]) + value[i];
	int withoutCurrObject = GetZeroOnePackage(i-1,j);
	result[i][j] =  max(withCurrObject,withoutCurrObject);

	return result[i][j];
}

int GetZeroOnePackage1(int w)
{
	for(int i = 0; i < N; i++)
		result[i][0] = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < w + 1; j++)
		{
			int withCurrObject = 0;
			if(j >= weight[i])
				withCurrObject = result[i-1][j-weight[i]] + value[i];
			int withoutCurrObject = result[i-1][j];
			result[i][j] =  max(withCurrObject,withoutCurrObject);
		}
	}

	return result[N-1][w-1];
}


int _tmain(int argc, _TCHAR* argv[])
{
	memset(result,-1,5*11*sizeof(int));
	//int v = GetZeroOnePackage(4,10);
	int v1 =  GetZeroOnePackage1(10);
	return 0;
}