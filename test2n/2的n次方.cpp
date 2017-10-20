// test2n.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

bool Is2N_1(int x)
{
	int i = 1;
	while(1)
	{
		if(i == x)   return true;
		else if(i > x)  return false;
		i *= 2;
	}
}

bool Is2N_2(int x)
{
	while(x % 2 == 0)
		x /= 2;
	return x == 1;
}

bool Is2N_3(int x)
{
	double a = log(x)/log(2);
	return(x == pow(2,a));
}

bool Is2N_4(int x)
{
	return !(x&x-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 32;
	bool is2n1 = Is2N_1(a);
	bool is2n2 = Is2N_2(a);
	bool is2n3 = Is2N_3(a);
	bool is2n4 = Is2N_4(a);
	return 0;
}
