#pragma once
#include <vector>
#include <list>

using namespace std;

class AdjacencyList
{
private:
	vector<list<int>> adj;

public:
	AdjacencyList(int n);
	~AdjacencyList();
	void addEdge(int vert, int neigh);
	bool isNeighbor(int vert, int neigh);
	list<int>& getNeighbors(int vert);
};

