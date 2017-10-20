// �ֵ���ȫ����.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//�ҵ���һ�����<�ұߵ���X = nums[firstLessIndex]��firstLessIndex��ȫ�ǵ���
	for(int i = s -1; i > 0; i--)
	{
		if(nums[i-1] < nums[i])
		{
			firstLessIndex = i -1;
			break;
		}
	}

	//���û�ҵ�
	if(firstLessIndex == -1)
		return false;

	for(int j = nums.size()-1; j > firstLessIndex; j--)
	{
		//�Ӻ���ǰ���ҵ���һ������X����Y
		if(nums[j] > nums[firstLessIndex])
		{
			//����X��Y
			swap(&nums[j], &nums[firstLessIndex]);

			//��firstLessIndex��ߵ�������
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
