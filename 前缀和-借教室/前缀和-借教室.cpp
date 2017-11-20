// 前缀和-借教室.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

int N = 4;		//提供的借用天数
int M = 3;		//订单数量
int room[100] = {2,5,4,3};	//每一天提供的教室数量
int cnt[100] = {2,3,4};		//每一订单请求的教室数量
int start[100] = {1,2,2};	//每一订单的其实时间
int end[100] = {3,4,4};		//每一订单的结束时间
int borrowStatus[100];		//借用教室的情况（前缀和）


//检查所有订单是否合法（每一个订单都能借到教室）
bool Check()
{
	memset(borrowStatus,0,100*sizeof(int));

	for(int i = 0; i < M; i++)
	{
		int sTime = start[i];
		int eTime = end[i];

		borrowStatus[sTime] += cnt[i];   //将每一个订单的起始位置加上借的数量
		borrowStatus[eTime + 1] -= cnt[i]; //将每一个订单的结束位置减去借的数量
		//保证在startTime和endTime之间求和的话，每一天都必有一个数量，就是cnt[i]
		//过了结束时间，再减去cnt[i]，表明cnt[i]这一数量不再需要
	}
	//订单1借后的情况：2 0 0 -2     那么前3天求和 应该是2，实际上前3天每天都能提供2教室，第4天求和为0，不再需要教室
	//订单2借后的情况：2 3 0 -2 -3  前2项求和为5，表明第2天需要5教室（第1天2，第2天3） ，第3天求和仍为5，但教室不够

	int ans = 0;
	for(int j = 0; j < N; j++)
	{
		ans += borrowStatus[j];	//第j天需要的教室数量
		if(ans < cnt[j])		//如果第j天需要的教室数量 < 第j天能提供的数量 那么error
			return false;
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

