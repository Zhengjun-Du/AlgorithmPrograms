// TestSubset2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

//��һ�����ϵ������Ӽ�
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

//�����������Ӷ�O��2^n)
bool GetSubset2(vector<int>& arr, int size,int sum, vector<int>& result)
{
	//��������Ӽ�������һ���
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
	//�Ӻ���ǰ�����α���
	for(int i = size - 1; i >= 0; i--)
	{
		vector<int> currSet;
		int currsetSum = 0;

		//ÿһ�δӺ���ǰ
		for(int j = i; j >= 0; j--)
		{
			//����Ӽ��ĺ�С�ں͵�һ��  ��װ�뵱ǰԪ�أ���������
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

		//���ɵ�������ĺ�һ��Ҫ��ż��
		while(1)
		{
			sum = 0;
			srand(unsigned(time(0)));
			for(int i = 0; i < arr_size; i++)
			{
				arr[i] = rand() % 100;
				sum += arr[i];
			}

			//ֻ��ż��������ֹͣѭ��
			if(sum % 2 == 0)
				break;
		}

		//����
		sort(arr.begin(), arr.end());

		vector<int> result;
		vector<int> result_Chen;

		bool has2Set = GetSubset2(arr,arr_size,sum,result);
		bool has2Set_Chen = GetSubset2_Chen(arr,arr_size,sum,result_Chen);


		if(has2Set == true && has2Set_Chen == false)
		{
			cout<<"����İ������µķ������ܽ����"<<endl;
			cout<<"����ȫ��Ϊ��"<<endl;
			for(int m = 0; m < arr.size(); m++)
				cout<<arr[m]<<" ";
			cout<<endl;
			cout<<"����ͣ� "<<sum<<endl;

			int theSum = 0;
			for(int  i = 0; i < result.size(); i++)
			{
				theSum += result[i];
				cout<<result[i]<<"  ";
			}
			cout<<endl;
			cout<<"������ͣ� "<<theSum<<endl;
			break;
		}
	}
	return 0;
}