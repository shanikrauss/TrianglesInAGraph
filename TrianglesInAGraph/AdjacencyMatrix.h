#pragma once
#include <vector>
#include "AdjacencyList.h"
#include <cmath>

using namespace std;

class AdjacencyMatrix
{
private:
	int size;
	vector<vector<int>> graph;

public:

	AdjacencyMatrix();
	AdjacencyMatrix(AdjacencyList& adjList);
	AdjacencyMatrix(int size);
	AdjacencyMatrix(AdjacencyList& adjList, vector<int>& degArr);
	AdjacencyMatrix(const AdjacencyMatrix& other);
	const AdjacencyMatrix& operator=(const AdjacencyMatrix& other);
	~AdjacencyMatrix();

	int getSize();
	void addEdge(int vert, int neigh);
	bool isNeighbor(int vert, int neigh);
	vector<int>& getNeighbors(int vert); 
	vector<vector<int>>* multMatrix(const vector<vector<int>>& matrix) const;
	int calcCell(const vector<vector<int>>& matrix, int i, int j) const;
	const vector<int>& operator[](int i) const;
	vector<int>& operator[](int i);

	vector<vector<int>>* multMatrix(const AdjacencyMatrix& matrix) const;

};