// 和为K的组合.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void GetKSUM(int k, vector<int>& nums, int sum)
{
	static int solu[5];

	if( k >= nums.size())
	{
		int s = 0;
		for(int i = 0; i< nums.size(); i++)
		{
			if(solu[i] == 1)
				s += nums[i];
		}
		if(s == sum)
		{
			for(int i = 0; i< nums.size(); i++)
			{
				if(solu[i] == 1) 
					cout << nums[i]<<" + ";
			}
		}
	}

	else
	{
		solu[k] = 0;
		GetKSUM(k+1,nums,sum);

		solu[k] = 1;
		GetKSUM(k+1,nums,sum);
	}
}

int sum = 20;

void GetKSUM1(int k, vector<int>& nums, int csum)
{
	static int* select = new int[nums.size()];

	if(csum == sum)
	{
		for(int i = 0; i < k; i++)
			if(select[i] == 1)
				cout<<nums[i]<<"+";
		cout<<endl;
		return;
	}

	if( k >= nums.size())
		return;
	
	for(int i = 0; i <= 1; i++)
	{
		select[k] = i;
		if(csum + i* nums[k] <= sum)
			GetKSUM1(k+1, nums, csum + i* nums[k]);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	double x = 0.1+0.2;
	cout<<setprecision(60)<<x<<endl;
	int n = 5;
	int nums[5] = {2,4,5,8,10};
	vector<int> nums_(nums,nums+5);
	//GetKSUM(0,nums_,20);
	GetKSUM1(0,nums_,0);
	return 0;
}