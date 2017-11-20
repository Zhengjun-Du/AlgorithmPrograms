// 线段树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define LC (root<<1)
#define RC (root<<1 | 1)

int data[100];
int SUM[400];
int ADD[400];

//将子节点的SUM值更新到父节点
void PushUp(int root)
{
	SUM[root] = SUM[LC] + SUM[RC];
}

//将父节点的ADD标记->下放到子节点
//修改子节点的SUM值
void PushDown(int root, int size_l, int size_r)
{
	if(ADD[root])
	{
		ADD[LC] += ADD[root];
		ADD[RC] += ADD[root];

		SUM[LC] += size_l * ADD[root];
		SUM[RC] += size_r * ADD[root];

		ADD[root] = 0;
	}
}

//递归建立线段树，数据下标范围[L,R]
void Build(int root, int L, int R)
{
	if(L == R)
		SUM[root] = data[L];
	else
	{
		int mid = (L + R) / 2;
		Build(LC, L, mid);
		Build(RC, mid+1, R);

		PushUp(root);
	}
}

//区间修改：原始数据范围[L,R],修改区间[cl,cr],每个值增加val
//单点修改只需要将区间改为cl = cr即可
void Update(int root, int L, int R, int val, int cl, int cr)
{
	//如果[L,R] 包含于 [cl,cr]，更新[L,R]的root
	if(cl <= L && R <= cr)
	{
		ADD[root] += val;
		SUM[root] += (R - L + 1)*val;
		return;
	}

	//如果[L,R] 与 修改区间 无任何交集
	if(cr < L || R < cl)
		return;

	int mid = (L + R) / 2;

	//下推标记
	PushDown(root,mid-L+1,R-mid);
	
	//如果[cl,cr] 跟 [L,mid]有交集
	if(cl <= mid) 
		Update(LC,L,mid,val,cl,cr);  
	//如果[cl,cr] 跟 [mid+1,R]有交集
    if(mid < cr)
		Update(RC,mid+1,R,val,cl,cr);  

    PushUp(root);
}

//区间查询，递归查下去
int Query(int root, int L, int R, int ql, int qr)
{
	if(ql <= L && R <= qr)
		return SUM[root];
	if(qr < L || R < ql)
		return 0;

	int ans = 0;
	int mid = (L + R) / 2;
	PushDown(root,mid-L+1,R-mid);
	if(ql <= mid) 
		ans += Query(LC,L,mid,ql,qr);
	if(mid < qr)
		ans += Query(RC,mid+1,R,ql,qr);

	return ans;
}

int main()
{
	int n = 16;
	for(int i = 1; i <= n; i++)
		data[i] = i;

	Build(1,1,n);

	int x = Query(1,1,n,1,6);

	
	Update(1,1,n,5,1,8);
	Update(1,1,n,10,1,1);
	
	int y = Query(1,1,n,1,4);

	return 0;
}