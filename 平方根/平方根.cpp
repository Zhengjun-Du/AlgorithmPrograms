// ƽ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

double SqrtSecond(double num)
{
	const double eps = 0.000001;
	double low = 0;
	double high = num;
	double mid;
	while((high-low)>eps)
	{
		mid = (low+high)/2;
		
		if(mid*mid== num)
			return mid;
		if(mid*mid > num)
			high = mid;
		else
			low = mid;
	}
	return mid;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<SqrtSecond(10)<<endl;
	return 0;
}

