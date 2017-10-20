// 单链表右移K位.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct LinkNode
{
	int data;
	LinkNode* next;

	LinkNode(int d, LinkNode* pNode = NULL)
	{
		data = d;
		next = pNode;
	}
};


void RightMove(LinkNode*& head, int count, int n)
{
	int moveSteps = n % count;
	LinkNode* pNode = head;

	while(pNode != NULL && pNode->next != NULL) 
		pNode = pNode->next;
	pNode->next = head;
	for(int i = 0; i < count-moveSteps; i++)
		pNode = pNode->next;

	head = pNode->next;
	pNode->next = NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkNode* head = new LinkNode(1);
	LinkNode* pNode = head;

	int N = 10;
	for(int i = 2; i <= N; i++)
	{
		pNode->next = new LinkNode(i);
		pNode = pNode->next;
	}
	pNode = NULL;


	RightMove(head,N,12);

	return 0;
}

