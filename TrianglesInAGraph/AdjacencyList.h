#pragma once
#include <vector>
#include <list>

using namespace std;

class AdjacencyList
{
private:
	int size;
	vector<list<int>> adj;

public:
	AdjacencyList(int n);
	~AdjacencyList();
	int getSize();
	void addEdge(int vert, int neigh);
	bool isNeighbor(int vert, int neigh);
	list<int>& getNeighbors(int vert);



	/*
	Arbel up
	Shani down
	*/
};

