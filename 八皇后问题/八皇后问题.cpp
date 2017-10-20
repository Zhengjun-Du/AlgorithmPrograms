// 八皇后问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

bool isSafe(int* solu, int k)
{
	for(int i = 1; i < k; i++)
	{
		if(abs(solu[i] - solu[k]) == abs(i-k) || solu[i] == solu[k])
			return false;
	}
	return true;
}

void PlaceQueen(int k, int n)
{
	static int* solu = new int[n+1];
	if(k > n)
	{
		for(int i = 1; i <= n; i++)
			cout<<solu[i]<<" ";
		cout<<endl;
	}

	for(int j = 1; j <= n; j++)
	{
		solu[k] = j;
		if(isSafe(solu,k))
			PlaceQueen(k+1,n);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	PlaceQueen(1,4);
	return 0;
}

