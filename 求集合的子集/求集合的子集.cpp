// 求集合的子集.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void GetSubSet(int k, int n)
{
	static int* solu = new int[n+1];
	if(k > n)
	{
		for(int i = 1; i <= n; i++)
			//cout<<solu[i];
			if(solu[i] == 1)
				cout<<i<<" ";
		cout<<endl;
	}
	else
	{
		solu[k] = 0;
		GetSubSet(k+1, n);

		solu[k] = 1;
		GetSubSet(k+1, n);
	}
}

void GetSubSet(int n)
{
	int sum = 1<<n;
	for(int i = 0; i < sum; i++)
	{
		int index = i;
		for(int j = 1; j <= n ; j++)
		{
			if(index&1 == 1)
				cout<<j<<" ";
			index>>=1;
		}
		cout<<endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	GetSubSet(1,3);
	//GetSubSet(3);
	return 0;
}