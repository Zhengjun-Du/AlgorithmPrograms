// 回溯法全排列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define N 4

bool sameWithBeforeNums(int* solu, int k)
{
	for(int i = 0; i < k; i++)
	{
		if(solu[i] == solu[k])
			return true;
	}
	return false;
}

void trackback_1(int k)
{
	static int solu[N];
	if(k == N)
	{
		for(int i = 0; i < N; i++)
			cout<<solu[i];
		cout<<endl;
		return;
	}

	for(int i = 0; i < N; i++)
	{
		solu[k] = i+1;
		if(!sameWithBeforeNums(solu,k))
			trackback_1(k+1);
	}
}

/*
void trackback_2(int k)
{
	static int solu[N];
	while(k >= 0)
	{
		if(k == N)
		{
			for(int i = 0; i < N; i++)
				cout<<solu[i];
			cout<<endl;
			k--;
		}

		while(1)
		{
			solu[k]++;
			if(!sameWithBeforeNums(solu,k))
				break;
		}

		if(solu[k] == N + 1)
		{
			solu[k] = 0;
			k--;
		}
		else
			k++;
	}
}
*/

void trackback_2(int k)
{
	int solu[N];
	while(k >= 0)
	{
		if(k == N)
		{
			for(int i = 0; i < N; i++)
				cout<<solu[i];
			cout<<endl;
			k--;
		}

		while(1)
		{
			solu[k]++;
			if(!sameWithBeforeNums(solu,k))
				break;
		}

		if(solu[k] == N + 1)
		{
			solu[k] = 0;
			k--;
		}
		else
			k++;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	trackback_2(0);
	return 0;
}