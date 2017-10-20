// 01背包问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
using namespace std;

/* 递归超时
int ZeroOnePack(vector<int>&w,vector<int>&v,int n, int weight)
{
    if(n == 0 || weight == 0)
      return 0;
    
    int get_n =   weight-w[n-1] >= 0 ? ZeroOnePack(w,v,n-1,weight-w[n-1]) + v[n-1] : 0;
    int not_get_n =  ZeroOnePack(w,v,n-1,weight);
    return get_n > not_get_n ? get_n : not_get_n;
}
*/

int ZeroOnePack(vector<int>&w,vector<int>&v,int n, int weight)
{
    vector< vector<int> > value(n);
    for(int i = 0; i < n; i++)
     {
         vector<int> value_(weight);
         value[i] = value_;
     } 
     
     for(int i = 0; i < n; i++)  value[i][0] = 0;
     for(int j = 0; j < weight; j++) 
			 value[0][j] = j >= w[0] ? v[0] : 0;
           
     for(int i = 1; i < n; i++)
      {
          for(int j = 1; j < weight; j++)
            {
                int not_get_n =  value[i-1][j];
                int get_n = 0;
                if(j >= w[i])
                    get_n = value[i-1][j - w[i]] + v[i];
                
                value[i][j] = get_n > not_get_n ? get_n : not_get_n;
            }
      }
      return value[n-1][weight-1];
}

int main()
{
    int N,W;
    cin>>N>>W;
    
    vector<int> w(N);
    vector<int> v(N);
    
    for(int i = 0; i < N; i++)
        cin>>w[i]>>v[i];
    
    int maxv = ZeroOnePack(w,v,N,W);
    cout<<maxv;
    
    return 0;
}

