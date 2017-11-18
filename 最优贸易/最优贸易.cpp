// 最优贸易.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include < queue>  
#include < cmath>  
#include < vector>  
#include < cstdio>  
#include < cstdlib>  
#include < string>  
#include < cstring>  
#include < iostream>  
#include < algorithm>  
#define MAXN 100010  
#define INF 1000007  
using namespace std;  

int prices[MAXN],minv[MAXN],maxv[MAXN];  
int n,m;  
int ans  =  0;  
int vis[MAXN];			  //访问标记：访问1 未访问0
vector < int> e[MAXN];    //某个点指出去的边
vector < int> re[MAXN];   //指向某个点的边

void init()  //完成输入初始化
{  
	cin >>n>>m;  
	int x,y,z;  
	for (int i = 1;i <= n;i++) 
		scanf("%d",&prices[i]);  
	for (int i = 1;i <= m;i++) 
	{  
		scanf("%d%d%d",&x,&y,&z);  
		e[x].push_back(y);  
		re[y].push_back(x); 

		if (z == 2)
		{  
			e[y].push_back(x);  
			re[x].push_back(y);  
		}  
	}  
}  
void spfa1()
{  
	queue < int> q;  
	memset(vis,0,sizeof vis);  
	vis[1] = 1;
	minv[1] = prices[1]; 

	q.push(1);  

	while (!q.empty())  
	{  
		int u = q.front();  
		for (int i = 0;i < e[u].size();i++)  
		{  
			int v = e[u][i];  
			if (!minv[v])
				minv[v] = prices[v];  

			minv[v] = min(minv[v],minv[u]);  
			if (!vis[v])
			{  
				q.push(v);  
				vis[v] = 1;  
			}  
		}  
		q.pop();  
	}  
}  
void spfa2()
{  
	queue < int> q;  
	memset(vis,0,sizeof vis);  
	vis[n] = 1;
	maxv[n] = prices[n]; 
	q.push(n);  

	while (!q.empty())  
	{  
		int u = q.front();  
		for (int i = 0;i < re[u].size();i++)  
		{  
			int v = re[u][i];  
			if (!maxv[v]) 
				maxv[v] = prices[v];  
			maxv[v] = max(maxv[v],maxv[u]);  
			if (!vis[v])
			{  
				q.push(v);  
				vis[v] = 1; 
			}  
		}  
		q.pop();  
	}  
} 

int main()
{  
	init();  
	spfa1();  
	spfa2();  
	for (int i = 1;i <= n;i++) 
		ans  =  max(ans,maxv[i]-minv[i]); 
	cout << ans;  
	return 0;  
} 