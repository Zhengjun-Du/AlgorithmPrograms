// �߶���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define LC (root<<1)
#define RC (root<<1 | 1)

int data[100];
int SUM[400];
int ADD[400];

//���ӽڵ��SUMֵ���µ����ڵ�
void PushUp(int root)
{
	SUM[root] = SUM[LC] + SUM[RC];
}

//�����ڵ��ADD���->�·ŵ��ӽڵ�
//�޸��ӽڵ��SUMֵ
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

//�ݹ齨���߶����������±귶Χ[L,R]
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

//�����޸ģ�ԭʼ���ݷ�Χ[L,R],�޸�����[cl,cr],ÿ��ֵ����val
//�����޸�ֻ��Ҫ�������Ϊcl = cr����
void Update(int root, int L, int R, int val, int cl, int cr)
{
	//���[L,R] ������ [cl,cr]������[L,R]��root
	if(cl <= L && R <= cr)
	{
		ADD[root] += val;
		SUM[root] += (R - L + 1)*val;
		return;
	}

	//���[L,R] �� �޸����� ���κν���
	if(cr < L || R < cl)
		return;

	int mid = (L + R) / 2;

	//���Ʊ��
	PushDown(root,mid-L+1,R-mid);
	
	//���[cl,cr] �� [L,mid]�н���
	if(cl <= mid) 
		Update(LC,L,mid,val,cl,cr);  
	//���[cl,cr] �� [mid+1,R]�н���
    if(mid < cr)
		Update(RC,mid+1,R,val,cl,cr);  

    PushUp(root);
}

//�����ѯ���ݹ����ȥ
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