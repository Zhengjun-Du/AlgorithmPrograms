// 选择排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
	int t = a; a = b; b = t;
}

void SelectSort(vector<int>& vec)
{
	int size = vec.size();
	for(int hi = size - 1; hi > 0; hi--)
	{
		int maxIndex = 0;
		for(int j = 0; j <= hi; j++)
		{
			if(vec[maxIndex] < vec[j])
				maxIndex = j;
		}
		swap(vec[maxIndex],vec[hi]);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = {5,4,3,2,1};
	vector<int> vec(a,a+5);
	SelectSort(vec);
	return 0;
}
