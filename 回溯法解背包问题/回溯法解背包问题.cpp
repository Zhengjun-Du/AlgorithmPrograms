// 回溯法解背包问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n = 4;
int c = 6;
int v[4] = {9,20,17,5};
int w[4] = {3,5,2,1};
int maxValue = 0;
int sumValue = 40;

void Package(int k, int weight, int value)
{
	static int select[4];

	if(k >= 4)
	{
		if(maxValue < value)
		{
			maxValue = value;
			cout<<"Value:"<<maxValue<<endl;
			cout<<"weight:"<<weight<<endl;
			
			maxValue = value;
			for(int i = 0; i < 4; i++)
				if(select[i] == 1)
					cout<<"w: "<<w[i]<<" value: "<<v[i]<<endl;
			cout<<"==========================================="<<endl;
		}
		return;
	}

	for(int i = 1; i >= 0; i--)
	{
		select[k] = i;
		int currWeight = weight + i*w[k];
		int currValue = value + i*v[k];
		int remainValue = 0;
		for(int j = k+1; j < 4; j++)
			remainValue += v[j];

		if( currWeight <= c && currValue + remainValue > maxValue)
			Package(k+1,currWeight, currValue);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Package(0,0,0);
	return 0;
}