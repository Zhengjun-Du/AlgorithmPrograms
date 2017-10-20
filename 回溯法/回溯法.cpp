// 回溯法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

/*
template<typename Printable>
void PowerSet(vector<Printable> &vec,queue<Printable> que){
	if(que.empty()){
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<"  ";
		cout<<endl;
		return;
	}
	Printable ele=que.front();
	que.pop();
	vector<Printable> newvec(vec);
	vec.push_back(ele);
	PowerSet(newvec,que);
	PowerSet(vec,que);
}

int main(){
	string str="abc";
	queue<char> que;
	vector<char> vec;
	for(int i=0;i<str.size();i++)
		que.push(str[i]);
	PowerSet(vec,que);
	return 0;
}
*/

//组合数
int const n = 3;
void backtrack (int t)
{
	static int x[n];
	if (t>=n)
	{
		for(int i = 0; i < n; i++)
		{
			if(x[i] == 1)
				cout<<i+1<<" ";
		}
		cout<<endl;
		return;
	}

	x[t]=0;  backtrack(t+1); 
	x[t]=1;  backtrack(t+1); 
}

//排列数
int x[n] = {1,2,3};
void perm (int t)
{
	if (t>=n)
	{
		for(int i = 0; i < n; i++)
			cout<<x[i];
		cout<<endl;
		return;
	}

	for (int i=t;i<n;i++)
	{
		swap(x[t], x[i]);
		perm(t+1);
		swap(x[t], x[i]);
	}
} 


int  main()
{
	//backtrack(0);
	perm(0);
	return 0;
}


