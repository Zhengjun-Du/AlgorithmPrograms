// 最大公约数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	/*
    int A, B;
    cin>>A>>B;
    
    int max = (A > B) ? A : B;
    while(1)
    {
       if(max % A == 0 && max % B ==0) 
         {
             cout<<max;
             break;
         }
         max++;
    } */
 /*
	long long A, B;
    cin>>A>>B;
    
   超时
    int max = (A > B) ? A : B;
    while(1)
    {
       if(max % A == 0 && max % B ==0) 
         {
             cout<<max;
             break;
         }
         max++;
    } 
   */

	/*
   
   long long C = A;
   long long D = B;
   
   while(C % D != 0)
   {
       long long t = C;
       C = D;
       D = t % D;
   }
   
   cout<<A*B/D;
*/

	long long f = 1;
    int N,P;
    cin>>N>>P;
    
    for(int i = 1; i <= N; i++)
      f = f * i % P;
    
    cout<<f;
    return 0;
   
}