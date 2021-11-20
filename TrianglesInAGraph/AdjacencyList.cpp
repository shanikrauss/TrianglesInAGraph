#include "AdjacencyList.h"
#include <math.h>    

using namespace std;

AdjacencyList::AdjacencyList(int n) : adj(vector<list<int>>(n)), size(n), degrees(vector<int>(n))
{}

AdjacencyList::AdjacencyList(const AdjacencyList& other)
{
	*this = other;
}

const AdjacencyList& AdjacencyList::operator=(const AdjacencyList& other)
{
	if (this != &other)
	{
		size = other.size;
		numOfedges = other.numOfedges;
		adj = other.adj;
		degrees = other.degrees;
	}
	return *this;
}

AdjacencyList::~AdjacencyList()
{}

int AdjacencyList::getSize()
{
	return size;
}

bool AdjacencyList::isEdgeExist(int vert, int neigh)
{
	for (auto it = adj[vert - 1].begin(); it != adj[vert - 1].end(); it++)
	{
		if (*it == neigh)
		{
			return true;
		}
	}

	return false;
}

void AdjacencyList::addEdge(int vert, int neigh)
{
	if (!isEdgeExist(vert, neigh))
	{
		adj[vert - 1].push_back(neigh);
		numOfedges++;
		degrees[vert - 1]++;
		degrees[neigh - 1]++;
	}
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

vector<int>& AdjacencyList::getDegArr()
{
	return degrees;
}


/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////

int AdjacencyList::getEdges()
{
	return numOfedges;
}

bool AdjacencyList::isVertDegreSmall(int vert)
{
	return degrees[vert - 1] < sqrt(numOfedges) ? true : false;
}

