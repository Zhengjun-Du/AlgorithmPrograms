// Bitmap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define MAX 1024   //数的范围
#define MASK 0X1F  //求模运算
#define SHIFT 5    //2^5 = 32
#define INT_SIZE sizeof(int) //int的字节数

int bitmap[MAX / INT_SIZE];	 //存储数用的数组


void Set(int i)
{
	//i >> SHIFT: 右移5位 == i / 32 确定i存储在那一段
	//i & MASK:等效 i % 32, 确定存在哪一位
	//1 << (i & MASK): 将上面得到的位 置为 1， 这里从右到左，自低向高
	//最后与源数据做与运算
	bitmap[i >> SHIFT] |= (1 << (i & MASK));
}

int Get(int i)
{
	//将存储的那一位 & 1, 取得这一位是 1  还是 0

	return  (bitmap[i >> SHIFT] >> (i & MASK )) & 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(0));
	for(int i = 0; i < 20; i++)
	{
		int x = rand() % 1000;
		Set(x);
	}

	for(int i = 0; i < 1024; i++)
	{
		if(Get(i) == 1)  cout<<i<<" ";
	}

	return 0;
}
