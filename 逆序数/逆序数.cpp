// 逆序数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 0;
    cin>>N;
    vector<int> nums(N);
    
    for(int i = 0; i < N; i++)
        cin>>nums[i];
        
    if(N < 2)    
      return 0;
    
    int result = 0;
    for(int i = 1; i < N; i++)
    {
      int t = nums[i];
      int j = i;
      while(0 < j && t < nums[j-1])
       {
		   nums[j] = nums[j-1];
           result++;
           j--;
       }
	  nums[j] = t;
    }
    
    cout<<result;
    
    return 0;
}
