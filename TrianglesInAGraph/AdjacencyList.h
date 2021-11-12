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
	~AdjacencyList();
	int getSize();
	void addEdge(int vert, int neigh);
	bool isNeighbor(int vert, int neigh);
	list<int>& getNeighbors(int vert);
	vector<int>& getDegArr();


	/*
	Arbel up
	Shani down
	*/

	int getEdges();
	bool isVertDegreSmall(int vert);
};

