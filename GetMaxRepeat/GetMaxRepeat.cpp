// GetMaxRepeat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

int GetMaxRepeat(vector<int> data)
{
	vector<int> dataCounts(10000,0);
	for(int i = 0; i < data.size(); i++)
		dataCounts[data[i]]++;
	
	int max = 0;
	int pos = 0;
	for(int i = 0; i < dataCounts.size(); i++)
	{
		if(max < dataCounts[i])
		{
			max = dataCounts[i];
			pos = i;
		}
	}
	return pos;
}


int _tmain(int argc, _TCHAR* argv[])
{

	double f = 0.3;
	printf("%.17lf",0.3);

	int n = 0;
	cin>>n;
	vector<int> data(n);

	for(int i = 0; i < n; i++)
	{
		cin>>data[i];
	}

	int max = GetMaxRepeat(data);
	cout<<endl<<max;

	return 0;
}


/*
#include <stdio.h>

int main(int argc, char *argv[]) {
	  int N,arr[10001]={0};
	  scanf("%d",&N);
	   
	  for(int i=0;i<N;i++){
	 	int num=0;
	  	scanf("%d",&num);
	  	arr[num]=arr[num]+1;
	  }  
	    int m=0;
	  for(int j=0;j<N;j++){
	  	if(arr[m]<arr[j])
	  	m=j;
	  }
	  printf("%d",m);
	return 0;
}*/