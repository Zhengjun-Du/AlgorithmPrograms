// 拓扑排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;

/*测试数据
5 7
0 3 1
0 1 1
1 3 1
1 2 1
2 4 1
3 2 1
3 4 1
 测试数据*/

int _tmain(int argc, _TCHAR* argv[])
{
	Graph myGraph;
	myGraph.init();
	vector<int> topSortResult = myGraph.TopoSort();

	for(int i = 0; i < topSortResult.size(); i++)
		cout<<topSortResult[i]<<" ";
	cout<<endl;

	return 0;
}

