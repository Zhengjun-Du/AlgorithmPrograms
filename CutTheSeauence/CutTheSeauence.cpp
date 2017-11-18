// CutTheSeauence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int nums[8] = {2, 2, 2, 8, 1, 8, 2, 1};
int answer[8];
int N = 8, M = 9;

//f[i] = min(f[j] + max(a[j +1 , a[j + 2].....a[i])) j∈[0,i]
//f[i]表示从1到i按要求切分后，最大值相加后的最小值

void CutSequence()
{
	answer[0] = nums[0];  //初始化，第0个元素最小
	for(int i = 1; i < N; i++)
	{
		int sumj_i = 0;			//从i到j的和
		int Maxj_i = -1;		//从i到j的最大值
		answer[i] = INT_MAX;	//从0到i的解

		for(int j = i; j >= 0; j--) //从i往前的若干元素为最后一组
		{
			if(Maxj_i < nums[j])
				Maxj_i = nums[j];
			sumj_i += nums[j];

			if(sumj_i > M) //若最后一组超过M，退出
				break;

			if(j > 0)
			{
				if(answer[i] > Maxj_i + answer[j-1])
					answer[i] = Maxj_i + answer[j-1];
			}
			else
				answer[i] = Maxj_i;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CutSequence();
	return 0;
}