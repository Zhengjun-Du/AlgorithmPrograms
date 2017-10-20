// 涂色正方形的总数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	int x,y;
	Point(int x_, int y_): x(x_), y(y_){}
	bool operator == (const Point& point){return x == point.x && y == point.y;}
};

int GetColoredSquareCount(Point p1, Point p2, Point p3, Point p4)
{
	vector<Point> coloredSquares;
	for(int i = p1.x; i < p2.x; i++)
		for(int j = p1.y; j < p2.y; j++)
			coloredSquares.push_back(Point(i,j));

	for(int i = p3.x; i < p4.x; i++)
		for(int j = p3.y; j < p4.y; j++)
		{
			Point p(i,j);
			if(find(coloredSquares.begin(),coloredSquares.end(),p) == coloredSquares.end())
				coloredSquares.push_back(Point(i,j));
		}
	return coloredSquares.size();

}

int _tmain(int argc, _TCHAR* argv[])
{
	Point p1(1,1);
	Point p2(4,4);
	Point p3(2,3);
	Point p4(6,5);

	int m = GetColoredSquareCount(p1,p2,p3,p4);

	return 0;
}

