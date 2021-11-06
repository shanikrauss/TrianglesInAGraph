#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList(int n) : adj(vector<list<int>>(n))
{}

AdjacencyList::~AdjacencyList()
{}

void AdjacencyList::addEdge(int vert, int neigh)
{
	adj[vert].push_back(neigh);
}

bool AdjacencyList::isNeighbor(int vert, int neigh)
{
	bool isNeigh = false;

	for (auto it = adj[vert].begin(); it != adj[vert].end(); it++)
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
	return adj[vert];
}