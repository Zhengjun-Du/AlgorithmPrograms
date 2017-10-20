// 大数加法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

int GetBigNumAdd(string s1, string s2, int* sum)
{
  reverse(s1.begin(),s1.end());
  reverse(s2.begin(),s2.end());
  
  int i = 0,j = 0;
  int sindex = 0; 
  int nextBit = 0;
  while(i < s1.length() && j < s2.length())
  {
	  int n1 = s1[i++]-'0';
	  int n2 = s2[j++]-'0';
	  sum[sindex++] = (nextBit+n1+n2)%10;
	  nextBit = (nextBit+n1+n2) / 10;
  }
  while(i < s1.length())
  {
	  int n1 = s1[i++]-'0';
	  sum[sindex++] = (nextBit + n1)%10;
	  nextBit = (nextBit + n1) / 10;
  }
  while(j < s2.length())
  {
	  int n2 = s2[j++]-'0';
	  sum[sindex++] = (nextBit + n2)%10;
	  nextBit = (nextBit + n2) / 10;
  }
  if(nextBit != 0)
	sum[sindex] += nextBit;
  return sindex;
}

int GetBigNumMinus(string s1, string s2, int* diff)
{
  reverse(s1.begin(),s1.end());
  reverse(s2.begin(),s2.end());
  
  int i = 0,j = 0;
  int sindex = 0; 
  bool brrowBit = false;
  while(i < s1.length() && j < s2.length())
  {
	  int n1 = s1[i++]-'0';
	  int n2 = s2[j++]-'0';
	  diff[sindex++] = brrowBit ?  (n1-1+10-n2)%10 : (n1+10-n2)%10;
	  brrowBit = (n1 < n2)? true : false;
  }

   while(i < s1.length())
  {
	  int n1 = s1[i++]-'0';
	  int n2 = 0;
	  diff[sindex++] = brrowBit ?  (n1-1+10-n2)%10 : (n1+10-n2)%10;
	  brrowBit = (n1 < n2)? true : false;
  }

  while(j < s2.length())
  {
	  int n1 = 0;
	  int n2 = s2[j++]-'0';
	  diff[sindex++] = brrowBit ?  (n1-1+10-n2)%10 : (n1+10-n2)%10;
	  brrowBit = (n1 < n2)? true : false;
  }
 
  return sindex;
}

int GetBigNumSum(string s1, string s2, int* S, bool& isPositive)
{
	bool n1_positive = (s1[0] != '-');
	bool n2_positive = (s2[0] != '-');
	int size = 0;
	if(n1_positive == n2_positive)
	{
		if(!n1_positive)
		{
			s1.erase(s1.begin());
			s2.erase(s2.begin());
			isPositive = false;
		}
		return  GetBigNumAdd(s1,s2,S); 
	}

	if(!n1_positive)
	{
		s1.erase(s1.begin());
		if(s1.compare(s2) == 1)
		{
			isPositive = false;
			return GetBigNumMinus(s1,s2,S);
		}
		else
		{
			isPositive = true;
			return GetBigNumMinus(s2,s1,S);
		}
	}

	else
	{
		s2.erase(s2.begin());
		if(s2.compare(s1) == 1)
		{
			isPositive = false;
			return GetBigNumMinus(s2,s1,S);
		}
		else
		{
			isPositive = true;
			return GetBigNumMinus(s1,s2,S);
		}
	}	
}

int main()
{
  string s_num1,s_num2;
  cin>>s_num1>>s_num2;

  int maxLen = s_num1.length();
  if(maxLen < s_num2.length()) maxLen = s_num2.length();
  int* sum = new int[maxLen+1];
  memset(sum,0,(maxLen+1)*sizeof(int));

  bool isPositive;
  int count = GetBigNumSum(s_num1,s_num2,sum,isPositive);

  int i = count;
  while(sum[i] == 0) i--;
  if(i==-1) cout<<0;
  if(!isPositive) cout<<"-";
  for(; i >= 0; i--)
	  cout<<sum[i];

  return 0;
}