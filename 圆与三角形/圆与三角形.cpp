// 圆与三角形.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;




int main()
{
    int m,n;
    cin>>m>>n;
    
    int** lattics = new int*[m];
    for(int i = 0; i < m; i++)
        lattics[i] = new int[n];

    for(int i = 0; i < m; i++)
       lattics[i][0] = 1;
    for(int j = 0; j < n; j++)
       lattics[0][j] = 1;
       
    for(int k = 1; k < m; k++)
    {
        for(int q = 1; q < n; q++)
        {
          lattics[k][q] = lattics[k-1][q] + lattics[k][q-1];
          lattics[k][q]%=1000000007;
        }
    }
    
    cout<<lattics[m-1][n-1];
    
    
    
    
    
    return 0;
}