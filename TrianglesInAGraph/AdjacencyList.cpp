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