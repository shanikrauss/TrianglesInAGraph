#pragma once
#include <vector>
#include <list>

using namespace std;

class AdjacencyList
{
private:
	int size;
	double numOfedges;
	vector<list<int>> adj;
	vector<int> degrees;

public:
	AdjacencyList(int n);
	AdjacencyList(const AdjacencyList& other);
	const AdjacencyList& operator=(const AdjacencyList& other);
	~AdjacencyList();
	int getSize();
	void addEdge(int vert, int neigh);
	bool isEdgeExist(int vert, int neigh);
	bool isNeighbor(int vert, int neigh);
	list<int>& getNeighbors(int vert);
	vector<int>& getDegArr();
	int getEdges();
	bool isVertDegreSmall(int vert);
};

