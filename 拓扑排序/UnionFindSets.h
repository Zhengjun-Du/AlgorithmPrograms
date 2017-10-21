#include <vector>
using namespace std;

struct Node
{
	int rank;
	int set;
};

class UnionFindSet
{
	vector<Node> nodes;

	int GetSet(int x)
	{
		if(nodes[x].set == x)
			return x;
		else
			return GetSet(nodes[x].set);
	}

	void MakeSet(int n)
	{
		for(int i = 0; i < n; i++)
		{
			Node node;
			node.rank = 0;
			node.set = i;
			nodes.push_back(node);
		}
	}

	void Union(int x, int y)
	{
		int x_set = GetSet(x);
		int y_set = GetSet(y);

		if(nodes[x].rank  > nodes[y].rank)
			nodes[y].set = x;
		else
		{
			nodes[x].set= y;
			if(nodes[x].rank == nodes[y].rank)
				nodes[y].rank++;
		}
	}
};