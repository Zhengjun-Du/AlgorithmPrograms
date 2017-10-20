// count_sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
#include <iostream>
using namespace std;

void countSort(int* a, int n)
{
	int* c = new int[n];
	int* result = new int[n];
	memset(c,0,n*sizeof(int));
	memset(result,-1,n*sizeof(int));

	for(int i = 0; i < n; i++)
	{
		int x = a[i];
		int lessNum = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[j] < x)  lessNum++;
		}

		while(result[lessNum] != -1) lessNum++;
		result[lessNum] = x;
	}

	for(int i = 0; i < n; i++)
		cout<<result[i]<<"";
}

void countSort_1(int* a, int n)
{
	int* c = new int[n];
	int* result = new int[n];
	memset(c,0,n*sizeof(int));
	memset(result,-1,n*sizeof(int));

	for(int i = 0; i < n; i++)
		c[a[i]]++;
	for(int j = 1; j < n; j++)
		c[j] = c[j] + c[j-1];

	int start = 0;
	for(int i = 0; i < n; i++)
	{
		while(start < c[i])
			result[start++] = i;
	}
	for(int i = 0; i < n; i++)
		cout<<result[i]<<"";
}


void countSort_2(int* a, int n)
{
	int* c = new int[n];
	int* result = new int[n];
	memset(c,0,n*sizeof(int));
	memset(result,-1,n*sizeof(int));

	for(int i = 0; i < n; i++)
		c[a[i]]++;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < c[i]; j++)
			cout<<i<<"";
}


int _tmain(int argc, _TCHAR* argv[])
{
	//int a[10] = {3,3,2,4,4,7,7,5,5,1};
	int a[8] = {2,5,3,0,2,3,0,3};
	countSort_2(a,8);	
	return 0;
}

