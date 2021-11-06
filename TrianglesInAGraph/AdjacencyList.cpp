#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList(int n) : adj(vector<list<int>>(n)), size(n)
{}

AdjacencyList::~AdjacencyList()
{}

int AdjacencyList::getSize()
{
	return size;
}

void AdjacencyList::addEdge(int vert, int neigh)
{
	adj[vert - 1].push_back(neigh);
}

bool AdjacencyList::isNeighbor(int vert, int neigh)
{
	bool isNeigh = false;

	for (auto it = adj[vert - 1].begin(); it != adj[vert - 1].end(); it++)
	{
		if (*it == neigh)
		{
			isNeigh = true;
			break;
		}
	}

	return isNeigh;
}

list<int>& AdjacencyList::getNeighbors(int vert)
{
	return adj[vert - 1];
}



/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////