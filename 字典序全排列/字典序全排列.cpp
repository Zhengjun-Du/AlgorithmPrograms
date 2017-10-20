// 字典序全排列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

bool GetNextPerm(vector<int>& nums)
{
	int firstLessIndex = -1;
	int s =  nums.size();

	//找到第一个左边<右边的数X = nums[firstLessIndex]，firstLessIndex后全是倒序
	for(int i = s -1; i > 0; i--)
	{
		if(nums[i-1] < nums[i])
		{
			firstLessIndex = i -1;
			break;
		}
	}

	//如果没找到
	if(firstLessIndex == -1)
		return false;

	for(int j = nums.size()-1; j > firstLessIndex; j--)
	{
		//从后往前，找到第一个大于X的数Y
		if(nums[j] > nums[firstLessIndex])
		{
			//交换X和Y
			swap(&nums[j], &nums[firstLessIndex]);

			//将firstLessIndex后边的数逆置
			int k,m;
			for(k = firstLessIndex + 1,m = s-1; k < m; k++, m--)
				swap(&nums[k],&nums[m]);
			return true;
		}
	}
}

int main()
{
	int N = 4;
	vector<int>  nums(N);
	for(int i = 0; i < N; i++)
		nums[i] = i+1;

	while(1)
	{
		for(int i = 0; i < nums.size(); i++)
			cout<<nums[i];
		cout<<endl;
		if(GetNextPerm(nums) == false) 
			break;
	}

	return 0;
}
