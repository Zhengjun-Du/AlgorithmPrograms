// 真实的排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

//ofstream of_in("case10.in");
//ofstream of_out("case10.out");


void Sort(vector<int> data)
{
	vector<int> rank(data.size());
	for(int i = 0; i < data.size(); i++)
	{
		rank[i] = 0;
		for(int j = 0; j < data.size(); j++)
		{
			if( data[i] < data[j])
				rank[i]++;
		}
		rank[i]++;
		cout<<setw(3)<<rank[i]<<" ";

		//of_out<<rank[i]<<" ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> data;
	srand(time(0));

	int n = 0;
	cin>>n;
	//of_in<<n<<endl;

	for(int i = 0; i < n; i++)
	{
		data.push_back(rand() % 101);
		cout<<setw(3)<<data[i]<<" ";
		//of_in<<data[i]<<" ";
	}
	cout<<endl;
	//of_in<<endl;

	Sort(data);

	return 0;
}