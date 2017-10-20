// RGBsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void quiksort(vector<int>& a)
{
	int red = 0, blue = a.size() - 1;
	for (int i = 0; i < blue + 1;) {
		if (a[i] == 0)  swap(&a[i++], &a[red++]);
		else if (a[i] == 2) swap(&a[i],&a[blue--]);
		else  i++;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10;
	vector<int> a(n);
	srand((unsigned int)time(NULL));
	for(int i = 0; i < n; i++)
		a[i] = rand()%3;
	quiksort(a);
	return 0;
}