// Bitmap.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define MAX 1024   //���ķ�Χ
#define MASK 0X1F  //��ģ����
#define SHIFT 5    //2^5 = 32
#define INT_SIZE sizeof(int) //int���ֽ���

int bitmap[MAX / INT_SIZE];	 //�洢���õ�����


void Set(int i)
{
	//i >> SHIFT: ����5λ == i / 32 ȷ��i�洢����һ��
	//i & MASK:��Ч i % 32, ȷ��������һλ
	//1 << (i & MASK): ������õ���λ ��Ϊ 1�� ������ҵ����Ե����
	//�����Դ������������
	bitmap[i >> SHIFT] |= (1 << (i & MASK));
}

int Get(int i)
{
	//���洢����һλ & 1, ȡ����һλ�� 1  ���� 0

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
