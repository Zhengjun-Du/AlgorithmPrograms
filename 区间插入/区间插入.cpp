// 区间插入.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int x0, x1;
	Interval(int x0_, int x1_)
	{
		x0 = x0_;
		x1 = x1_;
	}
};

void Insert(vector<Interval>& ints, Interval newInt)
{
	vector<Interval> result;
	int i = 0;
	while(i<ints.size())
	{
		if(newInt.x1 < ints[i].x0 )
				break;
		else if(ints[i].x1 < newInt.x0)
				result.push_back(ints[i]);
		else
		{
			newInt.x0 = min(newInt.x0,ints[i].x0);
			newInt.x1 = max(newInt.x1,ints[i].x1);
		}
	}
	result.push_back(newInt);
	while(i<ints.size())
		result.push_back(ints[i]);
	ints = result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Interval> ints;
	ints.push_back(Interval(1,2));
	ints.push_back(Interval(3,5));
	ints.push_back(Interval(6,7));
	ints.push_back(Interval(8,10));
	ints.push_back(Interval(12,16));

	Insert(ints,Interval(-1,1));

	return 0;
}

