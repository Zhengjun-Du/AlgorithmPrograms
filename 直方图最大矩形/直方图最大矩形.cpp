// 直方图最大矩形.cpp : 定义控制台应用程序的入口点。
//

// Test_3.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <vector>
#include <stack>
#include<iostream>
using namespace std;

int largestRectangleArea(vector<int>& height) 
{
	stack<int> index_height;
	height.push_back(0);        //加入立柱0，作为结尾判断
	int area = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (index_height.empty() || (!index_height.empty() && height[i] >= height[index_height.top()]))
			//如果比栈顶的高度大，则进栈，构建单调栈
				index_height.push(i);
		else
		{
			//比栈顶的高度小，开始依次出栈，并记录下标
			while (!index_height.empty() && height[index_height.top()] > height[i])
			{
				int index = index_height.top(); 
				index_height.pop();
				int width = index_height.empty() ? i : (i - index_height.top() - 1);
				//计算弹出的面积
				area = max(area, height[index] * width);
			}
			index_height.push(i);  // 将当前进栈
		}
	}
	return area;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> height;
	/*
	height.push_back(6);
	height.push_back(2);
	height.push_back(5);
	height.push_back(4);
	height.push_back(5);
	height.push_back(1);
	height.push_back(6);*/

	height.push_back(3);
	height.push_back(2);
	height.push_back(2);


	int m = largestRectangleArea(height);

	return 0;
}

