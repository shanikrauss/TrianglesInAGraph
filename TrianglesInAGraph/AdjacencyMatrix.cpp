#include "AdjacencyMatrix.h"
//#include<iostream>

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(int size) : graph(vector<vector<int>>(size))
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			graph[i][j] = 0;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	 
}

void AdjacencyMatrix::addEdge(int vert, int neigh) //function to add edge into the matrix
{			
	graph[vert][neigh] = 1;
}

bool AdjacencyMatrix::isNeighbor(int vert, int neigh)
{
	return graph[vert][neigh];
}

vector<int> AdjacencyMatrix::getNeighbors(int vert)
{
	return graph[vert];
}



