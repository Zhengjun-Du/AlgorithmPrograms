// BinarySearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;
vector<int> data;

//1.一般方法，找到即可，不考虑位置
int BinarySearch_v1(int e, int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(data[mid] < e)
			lo = mid + 1;
		else if(e < data[mid])
			hi = mid;
		else
			return mid;
	}
	return -1;
}

//2.[0,lo) <= e, [hi,n) > e, 重复的话返回最后一个
int BinarySearch_v2(int e, int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(e < data[mid])
            hi = mid;
        else
            lo = mid + 1;
	}

	if(data[lo - 1] == e)  
		return lo - 1;
	return -1;
}

//3.[0,lo) < e, [hi,n) >= e，重复的话返回第1个
int BinarySearch_v3(int e, int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(data[mid] < e)
           lo = mid + 1;
        else
           hi = mid;
	}

	if(data[lo] == e)  
		return lo;
	return -1;
}

//4.[0,lo) < e, [hi,n) >= e, 恰好比e小的数
int BinarySearch_v4(int e, int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(data[mid] < e)
           lo = mid + 1;
        else
           hi = mid;
	}

	if(lo > 0)
		return lo - 1;
	return lo ;
}

//5.[0,lo) <= e, [hi,n) > e, 恰好比e大的数
int BinarySearch_v5(int e, int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(e < data[mid])
            hi = mid;
        else
            lo = mid + 1;
	}

	if(lo < data.size())
		return lo ;
	return -1;
}


//6.一般方法，找到即可，不考虑位置
int BinarySearch_v6(int e, int lo, int hi)
{
	while(lo < hi - 1)
	{
		int mid = (lo + hi) / 2;
		if(data[mid] <= e)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n = 20;
    srand((unsigned int)time(NULL));
 
    for(int i = 0; i < n; i++)
        data.push_back(rand() % 30);
 
    sort(data.begin(), data.end());
 
    cout.setf(ios::left);
    for(int i = 0; i < n; i++)
        cout<<setw(2)<<i<<" ";
    cout<<endl;
 
    for(int i = 0; i < n; i++)
        cout<<setw(2)<<data[i]<<" ";
    cout<<endl;

	cout<<"search:-----------------------------------------"<<endl;
 
    while(1)
    {
        int x = 0;
        cin>>x;
        int m = BinarySearch_v6(x,0,data.size());
 
        if(m == -1)
            cout<<"not exist"<<endl;
        else
            cout<<"data["<<m<<"] = "<<data[m]<<endl;
    }
 
    return 0;
}
