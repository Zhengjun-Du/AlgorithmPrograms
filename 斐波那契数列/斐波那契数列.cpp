// 斐波那契数列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define INF 1000000009

__int64 GetFn1(int n)
{
	 __int64 F1 = 1, F2 = 1;
    if(n <= 2)
      return 1;
    else
    {
        for(int i = 3; i <= n; i++)
          {
              __int64 t = F1;
              F1 = F1 % INF + F2 % INF;
              F2 = t;
          }
          
         F1 %= INF;
         return F1;
    }
}

void getMatrix2N(int& a0_0, int& a0_1, int n)
{
	int a0_0_ = 1, a0_1_ = 1, a1_0_ = 1, a1_1_ = 0;
	for(int i = 0; i < n-1; i++)
	{
		int a = a0_0_ + a0_1_;
		int b = a0_0_;
		int c = a1_0_+ a1_1_;
		int d = a1_0_;
		a0_0_ = a; a0_1_ = b; a1_0_ = c; a1_1_ = d;
	}
	
		a0_0 = a0_0_; a0_1 = a0_1_; 
}

__int64 GetFn2(int n)
{
    if(n <= 2)
      return 1;
    else
    {
        int a0_0 = 1, a0_1 = 1, a1_0 = 1, a1_1 = 0;
		getMatrix2N(a0_0,a0_1,n-2);

		__int64 F = a0_0 % INF + a0_1 % INF;

    }
}

int main()
{
    __int64 n;
    cin>>n;
	int i = 3;
	for(; i < 100; i++)
	{
		__int64 Fn = GetFn2(i);
		__int64 Fn1 = GetFn1(i);
		if(Fn != Fn1)
		{
			int m = 3;
		}
	}
	//cout<<Fn;
   
    return 0;
}
