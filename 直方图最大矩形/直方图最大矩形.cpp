// ֱ��ͼ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

// Test_3.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <vector>
#include <stack>
#include<iostream>
using namespace std;

int largestRectangleArea(vector<int>& height) 
{
	stack<int> index_height;
	height.push_back(0);        //��������0����Ϊ��β�ж�
	int area = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (index_height.empty() || (!index_height.empty() && height[i] >= height[index_height.top()]))
			//�����ջ���ĸ߶ȴ����ջ����������ջ
				index_height.push(i);
		else
		{
			//��ջ���ĸ߶�С����ʼ���γ�ջ������¼�±�
			while (!index_height.empty() && height[index_height.top()] > height[i])
			{
				int index = index_height.top(); 
				index_height.pop();
				int width = index_height.empty() ? i : (i - index_height.top() - 1);
				//���㵯�������
				area = max(area, height[index] * width);
			}
			index_height.push(i);  // ����ǰ��ջ
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

