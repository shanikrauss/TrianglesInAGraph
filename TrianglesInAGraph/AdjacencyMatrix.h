#pragma once
#include <vector>

using namespace std;

class AdjacencyMatrix
{
private:
	int size;
	vector<vector<int>> graph;

public:
	AdjacencyMatrix();
	AdjacencyMatrix(int size);

	~AdjacencyMatrix();

	int getSize();

	void addEdge(int vert, int neigh);

	bool isNeighbor(int vert, int neigh);

	vector<int> getNeighbors(int vert); // should we return as referns / pointer

	vector<vector<int>> multMatrix(const vector<vector<int>>& matrix);

	int calcCell(const vector<vector<int>>& matrix, int i, int j);
};

