// 字符串组合最大整数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
# include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <atlstr.h>
using namespace std;


string int2string(int x)
{
	string s="";
	while(x > 0)
	{
		char c = x%10+'0';
		s.push_back(c);
		x/=10;
	}
	reverse(s.begin(), s.end());
	return s;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	cin>>n;

	vector<int> nums(n);
	vector<CString>  strs(n);
	for(int i = 0; i < n; i++)
	{
		cin>>nums[i];
		strs[i] = int2string(nums[i]).c_str();
	}

	sort(strs.begin(),strs.end());
	for(int i = n-1; i >= 0; i--)
		cout<<strs[i];
		

	return 0;
}