// quiksort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <vector>
using namespace std;

int partion(vector<int>& nums, int lo, int hi)
{
	int pivot = nums[lo];

	while(lo < hi)
	{
		while(lo < hi &&  pivot < nums[hi]) hi--;
		if(lo < hi) nums[lo] = nums[hi];

		while(lo < hi && nums[lo] < pivot) lo++;
		if(lo < hi) nums[hi] = nums[lo];
	}

	nums[lo] = pivot;
	return lo;
}

void QuickSort(vector<int>& nums, int lo, int hi)
{
	if(hi - lo <= 1)
		return;

	int mid = partion(nums,lo, hi-1);

	QuickSort(nums, lo, mid);
	QuickSort(nums, mid+1, hi);
}

int main()
{
	int N = 0;
	cin>>N;

	vector<int> nums(N);
	for(int i = 0; i < N; i++)
		cin>>nums[i];

	QuickSort(nums, 0, nums.size());
	for(int i = 0; i < N; i++)
		cout<<nums[i]<<endl;
	return 0;
}