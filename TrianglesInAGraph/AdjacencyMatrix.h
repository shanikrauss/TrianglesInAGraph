#pragma once
#include <vector>

using namespace std;

class AdjacencyMatrix
{
private:
	vector<vector<int>> graph;

public:
	AdjacencyMatrix();
	AdjacencyMatrix(int size);

	~AdjacencyMatrix();

	void addEdge(int vert, int neigh);

	bool isNeighbor(int vert, int neigh);

	vector<int> getNeighbors(int vert); // should we return as referns / pointer
};

