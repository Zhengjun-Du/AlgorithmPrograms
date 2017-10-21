#include <vector>
#include <iostream>
using namespace std;

struct Edge
{
	int u, v, w;
	Edge* nextEdge;

	Edge(int u_, int v_, int w_, Edge* nextEdge_ = NULL)
	{
		u = u_; v = v_; w = w_;
		nextEdge = nextEdge_;
	}
};

struct Vertex
{
	int data;
	Edge* firstEdge;
	bool visited;

	Vertex(int data_, Edge* firstEdge_ = NULL, bool visited_ = false)
	{
		data = data_;
		firstEdge = firstEdge_;
		visited = visited_;
	}
};

class Graph
{
public:
	vector<Vertex*> vertices;
	vector<Edge*> edges;

	void init()
	{
		int vertCnt,edgeCnt;
		cin>>vertCnt>>edgeCnt;

		for(int i = 0; i < vertCnt; i++)
			vertices.push_back(new Vertex(i));

		int u, v, w;
		for(int i = 0; i < edgeCnt; i++)
		{
			cin>>u>>v>>w;
			InserEdge(u,v,w);
		}
	}

	void InserEdge(int u, int v, int w)
	{
		Edge* edge = new Edge(u,v,w);
		edges.push_back(edge);

		Edge* currFirstEdge = vertices[u]->firstEdge ;
		if(currFirstEdge != NULL)
			edge->nextEdge = currFirstEdge;
		vertices[u]->firstEdge = edge;
	}

	int GetZeroInDegreeVert()
	{
		vector<int> zeroInDegreeVert(vertices.size(),0);
		for(int i = 0; i < vertices.size(); i++)
		{
			if(!vertices[i]->visited)
			{
				vector<int> AdjVertices = GetAdjVertices(i);
				for(int j = 0; j < AdjVertices.size(); j++)
					zeroInDegreeVert[AdjVertices[j]]++;
			}
		}

		for(int k = 0; k < vertices.size(); k++)
		{
			if(!vertices[k]->visited && zeroInDegreeVert[k] == 0)
				return k;
		}

		return -1;
	}

	vector<int> GetAdjVertices(int vertIndex)
	{
		vector<int> adjVertices;
		Edge* pEdge = vertices[vertIndex]->firstEdge;
		while(pEdge != NULL)
		{
			adjVertices.push_back(pEdge->v);
			pEdge = pEdge->nextEdge;
		}
		return adjVertices;
	}

	vector<int> TopoSort()
	{
		vector<int> topSortResult;

		while(1)
		{
			int zeroVertIndex = GetZeroInDegreeVert();
			if(zeroVertIndex == -1)
				return topSortResult;

			topSortResult.push_back(zeroVertIndex);
			vertices[zeroVertIndex]->visited = true;
		}
	}
};