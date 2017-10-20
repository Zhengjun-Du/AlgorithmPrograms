// TestSubset2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

//求一个集合的所有子集
vector< vector<int> > GetAllSubset(vector<int>&  arr, int size)
{	
	int subset_size = 1<<size;
	vector< vector<int> > allSet(subset_size);
	for(int i = 1; i < subset_size; i++)
	{
		vector<int> currset;
		int j = i;
		int k = 0;
		while(j)
		{
			if(j&1)
				currset.push_back(arr[k]);
			j>>=1;
			k++;
		}
		allSet[i] = currset;
	}
	return allSet;
}

//暴力法，复杂度O（2^n)
bool GetSubset2(vector<int>& arr, int size,int sum, vector<int>& result)
{
	//求出所有子集，并逐一求和
	vector<vector<int> > allsubset = GetAllSubset(arr,size);
	for(int i = 1; i < allsubset.size(); i++)
	{
		int subsetSum = 0;
		for(int j = 0; j < allsubset[i].size(); j++)
			subsetSum += allsubset[i][j];

		if(subsetSum == sum / 2)
		{
			result = allsubset[i];
			return true;
		}
	}
	return false;
}

bool GetSubset2_Chen(vector<int>& arr, int size, int sum, vector<int>& result)
{
	//从后往前，依次遍历
	for(int i = size - 1; i >= 0; i--)
	{
		vector<int> currSet;
		int currsetSum = 0;

		//每一次从后往前
		for(int j = i; j >= 0; j--)
		{
			//如果子集的和小于和的一半  则装入当前元素，否则跳过
			if(arr[j] + currsetSum  <= sum / 2)
			{
				currSet.push_back(arr[j]);
				currsetSum += arr[j];
			}
		}

		if(currsetSum == sum / 2)
		{
			result = currSet;
			return true;
		}
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{

	int arr_size = 10;

	while(1)
	{
		vector<int> arr(arr_size);
		int sum = 0;

		//生成的随机数的和一定要是偶数
		while(1)
		{
			sum = 0;
			srand(unsigned(time(0)));
			for(int i = 0; i < arr_size; i++)
			{
				arr[i] = rand() % 100;
				sum += arr[i];
			}

			//只有偶数，方可停止循环
			if(sum % 2 == 0)
				break;
		}

		//排序
		sort(arr.begin(), arr.end());

		vector<int> result;
		vector<int> result_Chen;

		bool has2Set = GetSubset2(arr,arr_size,sum,result);
		bool has2Set_Chen = GetSubset2_Chen(arr,arr_size,sum,result_Chen);


		if(has2Set == true && has2Set_Chen == false)
		{
			cout<<"下面的案例，陈的方法不能解出："<<endl;
			cout<<"数组全集为："<<endl;
			for(int m = 0; m < arr.size(); m++)
				cout<<arr[m]<<" ";
			cout<<endl;
			cout<<"数组和： "<<sum<<endl;

			int theSum = 0;
			for(int  i = 0; i < result.size(); i++)
			{
				theSum += result[i];
				cout<<result[i]<<"  ";
			}
			cout<<endl;
			cout<<"子数组和： "<<theSum<<endl;
			break;
		}
	}
	return 0;
}