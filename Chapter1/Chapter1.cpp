// Chapter1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include  <iostream>
#include  <vector>
#include <unordered_map>
#include <map>
#include "iomanip"
using namespace std;


vector<vector<int> > permutation(int n, vector<int> numbers)
{
	//��ά�����������е����У���һά�����еĸ�������2ά��ÿһ��������������Ϊ���еĳ���
	vector<vector<int> > perm;
	if(n == 1)
	{
		perm.push_back(vector<int>(1,numbers[0]));
		return perm;
	}

	//���ҳ�ǰn-1��������������
	perm = permutation(n-1,numbers);
	vector<vector<int> > final_perm;

	//���ǰn-1������ÿһ�����У��ٽ���n����ʹ�ò�շ�����
	for(int i = 0; i < perm.size(); i++)
	{
		int size = perm[i].size();
		//for(int j = 0; j <= size; j++)
		for(int j = size; j >= 0; j--)
		{
			//�ӵ�0��λ�ÿ�ʼ���룬ֱ����ĩβһ�����ܹ�size�֣�ÿһ������һ���µ�����
			vector<int> p = perm[i];
			p.insert(p.begin()+j,1,numbers[n-1]);
			final_perm.push_back(p);
		}
	}
	return final_perm;
}

/*
vector<vector<int> > combination(vector<int> numbers, int m, int n)
{
vector<vector<int> > comb;
if(n == 1)
{
for(int i = 0; i < m; i++)
comb.push_back(vector<int>(1,numbers[i]));
return comb;
}

else if(n == m)
{
comb.push_back(vector<int>(m));
for(int i = 0; i < m; i++)
comb[0][i] = numbers[i];
}
}*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
int n = 5;
vector<int> numbers(n);
for(int i = 0; i < n; i++)
numbers[i] = i+1;

vector< vector<int> > subset = permutation(n,numbers);

for(int j = 0; j < subset.size(); j++)
{
cout<<"{";
for(int k = 0; k < subset[j].size(); k++)
{
if(subset[j][k] != -1)
cout<<subset[j][k]<<" ";
}
cout<<"}"<<endl;
}
return 0;
}
*/

/*
int longestConsecutive(vector<int> const& num) {
	map<int,int> m;
	for(int i = 0; i < num.size(); i++)
		m[num[i]] = num[i];

	/*
	unordered_map<int, bool> used;
	for (auto i : num) used[i] = false;
	
	int longest = 0;
	for (auto i : num) {
		if (used[i]) continue;
		int length = 1;
		used[i] = true;
		for (int j = i + 1; used.find(j) != used.end(); ++j) {
			used[j] = true;
			++length;
		}
		for (int j = i - 1; used.find(j) != used.end(); --j) {
			used[j] = true;
			++length;
		}
		longest = max(longest, length);
	}
	return longest;

	return 8;
}

int main(){

	vector<int> s;
	s.push_back(100);
	s.push_back(4);
	s.push_back(200);
	s.push_back(1);
	s.push_back(3);
	s.push_back(2);

	int x = longestConsecutive(s);

	return 0;
}*/


#include <stack>

int  main()
{

	stack<int, list<int> > st;

	return 0;
}


