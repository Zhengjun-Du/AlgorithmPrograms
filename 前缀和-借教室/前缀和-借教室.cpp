// ǰ׺��-�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

int N = 4;		//�ṩ�Ľ�������
int M = 3;		//��������
int room[100] = {2,5,4,3};	//ÿһ���ṩ�Ľ�������
int cnt[100] = {2,3,4};		//ÿһ��������Ľ�������
int start[100] = {1,2,2};	//ÿһ��������ʵʱ��
int end[100] = {3,4,4};		//ÿһ�����Ľ���ʱ��
int borrowStatus[100];		//���ý��ҵ������ǰ׺�ͣ�


//������ж����Ƿ�Ϸ���ÿһ���������ܽ赽���ң�
bool Check()
{
	memset(borrowStatus,0,100*sizeof(int));

	for(int i = 0; i < M; i++)
	{
		int sTime = start[i];
		int eTime = end[i];

		borrowStatus[sTime] += cnt[i];   //��ÿһ����������ʼλ�ü��Ͻ������
		borrowStatus[eTime + 1] -= cnt[i]; //��ÿһ�������Ľ���λ�ü�ȥ�������
		//��֤��startTime��endTime֮����͵Ļ���ÿһ�춼����һ������������cnt[i]
		//���˽���ʱ�䣬�ټ�ȥcnt[i]������cnt[i]��һ����������Ҫ
	}
	//����1���������2 0 0 -2     ��ôǰ3����� Ӧ����2��ʵ����ǰ3��ÿ�춼���ṩ2���ң���4�����Ϊ0��������Ҫ����
	//����2���������2 3 0 -2 -3  ǰ2�����Ϊ5��������2����Ҫ5���ң���1��2����2��3�� ����3�������Ϊ5�������Ҳ���

	int ans = 0;
	for(int j = 0; j < N; j++)
	{
		ans += borrowStatus[j];	//��j����Ҫ�Ľ�������
		if(ans < cnt[j])		//�����j����Ҫ�Ľ������� < ��j�����ṩ������ ��ôerror
			return false;
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

