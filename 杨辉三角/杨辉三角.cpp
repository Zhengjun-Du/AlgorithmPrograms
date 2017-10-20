// 杨辉三角.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
int a[20][20];

void GetYanghuiTriangle(int n)
{
	for(int i = 0; i < n; i++)
	{
		a[i][0] = 1;
		for(int j = 1; j < i; j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		a[i][i] = 1;
	}	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
			cout<<setw(4)<<a[i][j]<<" ";
		cout<<endl;
	}
}

void GetYanghuiTriangle1(int n)
{
	int b[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < n; i++)
	{
		b[i] = 1;
		for(int j = i - 1; j > 0; j--)
			b[j] += b[j-1];

		for(int k = 0; k <= i; k++)
			cout<<setw(4)<<b[k]<<" ";
		cout<<endl;
	}	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10;
	GetYanghuiTriangle1(n);


	return 0;
}

