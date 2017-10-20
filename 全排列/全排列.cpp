#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//Ë³ÐòµÄÈ«ÅÅÁÐ
void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void perm(vector<int>& numbers, int lo, int hi) 
{
    if(lo >= hi)
      return;
	if(hi - lo == 1)
	{
		for(int i = 0; i < hi; i++)
				cout<<numbers[i];
			cout<<endl;
		return;
	}

    set<int> s;
	for(int i = lo; i < hi; i++)
	{
	    if(s.find(numbers[i]) == s.end())
		{
			s.insert(numbers[i]);
		    swap(&numbers[lo],&numbers[i]);
			sort(numbers.begin()+lo+1,numbers.end());
		    perm(numbers, lo+1,  hi);
		    // swap(&numbers[lo],&numbers[i]);
			sort(numbers.begin()+lo,numbers.end());
		}
	}
}

int main()
{
    char str[10];
    gets_s(str,10);
    vector<int> digits;
    char* pstr = str;
    while(*pstr != '\0')
     {
         digits.push_back(*pstr-'0');
         pstr++;
     }
    sort(digits.begin(),digits.end());
    perm(digits,0,digits.size());
    return 0;
}