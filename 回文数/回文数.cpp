// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <math.h>


bool IsPalindromeNumber(int x)
{
	int sum = 0;
	int n = x;
	while(n)
	{
		int low = n%10;
		sum = sum*10 + low;
		n /= 10;
	}
	return x == sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool test = IsPalindromeNumber(1234);
	bool test1 = IsPalindromeNumber(1234321);
	bool test3 = IsPalindromeNumber(1);

	return 0;
}

