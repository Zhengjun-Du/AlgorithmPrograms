// CutTheSeauence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int nums[8] = {2, 2, 2, 8, 1, 8, 2, 1};
int answer[8];
int N = 8, M = 9;

//f[i] = min(f[j] + max(a[j +1 , a[j + 2].....a[i])) j��[0,i]
//f[i]��ʾ��1��i��Ҫ���зֺ����ֵ��Ӻ����Сֵ

void CutSequence()
{
	answer[0] = nums[0];  //��ʼ������0��Ԫ����С
	for(int i = 1; i < N; i++)
	{
		int sumj_i = 0;			//��i��j�ĺ�
		int Maxj_i = -1;		//��i��j�����ֵ
		answer[i] = INT_MAX;	//��0��i�Ľ�

		for(int j = i; j >= 0; j--) //��i��ǰ������Ԫ��Ϊ���һ��
		{
			if(Maxj_i < nums[j])
				Maxj_i = nums[j];
			sumj_i += nums[j];

			if(sumj_i > M) //�����һ�鳬��M���˳�
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