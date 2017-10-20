// 输出1-n.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
vector<int> nums;
bool finish = false;

void PrintVector(vector<int> vec)
{
	int i = 0;
	while(i < vec.size() && vec[i++] == 0);

	i--;
	while(i < vec.size())
		cout<<vec[i++];
	cout<<endl;
}

void PrintOne2N(int k)
{
	static vector<int> selectNum(nums.size());

	if(selectNum == nums)
	{
			finish = true;
			return;
	}
	if(k >= nums.size())
	{
		PrintVector(selectNum);
		return;
	}

	for(int i = 0; i < 10; i++)
	{
		if(finish) 
			return;

		selectNum[k] = i;
		PrintOne2N(k+1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[100];
	cin>>str;
	int i = 0;
	while(str[i] != '\0')
	{
		nums.push_back(str[i]-'0');
		i++;
	}
	PrintOne2N(0);

	return 0;
}