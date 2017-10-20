// ջ��ϴ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n =3;

//��ջ�׵�ջ�����ջԪ��
void sequenceOutputStack(stack<int> s)
{
	while(s.empty())
		return;
	int top= s.top();s.pop();
	sequenceOutputStack(s);
	cout<<top<<" ";
}

//��sourceջ������destջ
void copyStack(stack<int>& source, stack<int>& dest, int n)
{
	while(n)
	{
		int top = source.top();
		dest.push(top);
		source.pop();
		n--;
	}
}

//��������ջ
stack<int> connectStack(stack<int>& s1, stack<int> s2)
{
	stack<int> result = s1;
	vector<int> s2_v;
	while(!s2.empty())
	{
		s2_v.push_back(s2.top());
		s2.pop();
	}

	for(int i = s2_v.size() -1;  i >= 0; i--)
		result.push(s2_v[i]);

	return result;
}

vector< stack<int> > stackPerm(stack<int> sourceStack,stack<int> destStack)
{
	vector< stack<int> > stacksVector;

	for(int i = 1; i <= sourceStack.size(); i++)
	{
		//���µ�ǰջ�ĵ�һ����
		stack<int> sourceStack_copy = sourceStack;
		int top = sourceStack_copy.top();
		sourceStack_copy.pop();

		//ǰi-1����ջ��ϴ
		stack<int> A;
		copyStack(sourceStack_copy,A,i-1);
		vector< stack<int> > x = stackPerm(A,destStack);

		//����top�����ڵ�i��λ��
		if(A.empty())
		{
			stack<int> s; s.push(top);
			x.push_back(s);
		}
		else 
		{	
			for(int j = 0; j < x.size(); j++)
				x[j].push(top);
		}

		//�����n-i����ջ��ϴ
		vector< stack<int> > y;
		if(!sourceStack_copy.empty())
		  y = stackPerm(sourceStack_copy,destStack);

		if(y.empty())
		{
			for(int k = 0; k < x.size(); k++)
				stacksVector.push_back(x[k]);
		}
		else
		{
			for(int j = 0; j < x.size(); j++)
				for(int k = 0; k < y.size(); k++)
					stacksVector.push_back(connectStack(x[j],y[k]));
		}
	}
	return stacksVector;
}


int _tmain(int argc, _TCHAR* argv[])
{
	stack<int> sourceStack,helpStack,destStack;
	for(int i = n; i >= 1; i--)
		sourceStack.push(i);

	cout<<"ԭʼջ��"<<endl;
	for(int i = 1; i <= n; i++)
		cout<<i<<" ";
	cout<<endl;

	vector< stack<int> > all_stack = stackPerm(sourceStack,destStack);
	cout<<"ջ��ϴ��������"<<all_stack.size()<<endl;
	for(int i = 0; i < all_stack.size(); i++)
	{
		sequenceOutputStack(all_stack[i]);
		cout<<endl;
	}

	return 0;
}