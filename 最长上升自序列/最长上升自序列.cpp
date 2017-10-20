// 最长上升自序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


void PrintLIS(vector<int>& nums, vector<int>& Lis, vector<int>& preds)
{
	int LastIndex = distance(Lis.begin(),max_element(Lis.begin(), Lis.end()));
	stack<int> LisSequence; 
	LisSequence.push(nums[LastIndex]);


	int scount = Lis[LastIndex];
	while(scount > 1)
	{
		LisSequence.push(nums[preds[LastIndex]]);
		LastIndex = preds[LastIndex];
		scount--;
	}

	while(!LisSequence.empty())
	{
		cout<<LisSequence.top()<<" ";
		LisSequence.pop();
	}
}

void GetLIS(vector<int>& nums)
{
	vector<int> Lis(nums.size(),1);
	vector<int> preds(nums.size(),-1);

	for(int i = 1; i < nums.size(); i++)
	{
		int pred = 0;
		for(int j = 0; j < i; j++)
		{
			if(nums[j] < nums[i] && Lis[j] + 1 > Lis[i])
			{
				Lis[i] = Lis[j] + 1 ;
				pred = j;
			}
		}
		preds[i] = pred;
	}

	PrintLIS(nums, Lis, preds);
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int N = 10;
	vector<int> nums;
	for(int i = 0; i < N; i++)
		nums.push_back(rand() % 1000);


	for(int i = 0; i < nums.size(); i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	GetLIS(nums);
	return 0;
}