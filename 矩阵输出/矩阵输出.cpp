// 矩阵输出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int n = 4;
const int m = 4;
int a[n][m];


void PrintRoundN(int r)
{
	int i = r, j = r;
	while(j < m -r) cout<<a[i][j++]<<" ";

	i = r + 1; j = m - r - 1;
	while(i < n-r) cout<<a[i++][j]<<" ";

	i = n - r - 1; j = m - r - 2;
	while(j >= r) cout<<a[i][j--]<<" ";

	i = n - r - 2; j = r;
	while(i > r) cout<<a[i--][j]<<" ";
}



int _tmain(int argc, _TCHAR* argv[])
{
	int x = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			a[i][j] = x++;

	cout.setf(ios::left);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout<<setw(4)<<a[i][j]<<" ";
		cout<<endl;
	}

	int rounds = (m+1)/2;
	cout<<"顺时针输出："<<endl;
	for(int i = 0; i < rounds; i++)
		PrintRoundN(i);
	cout<<endl<<endl<<endl<<endl;

	return 0;
}

