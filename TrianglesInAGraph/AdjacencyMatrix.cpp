#include "AdjacencyMatrix.h"
//#include<iostream>

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(int size) : graph(vector<vector<int>>(size)), size(size)
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

int AdjacencyMatrix::getSize()
{
	return size;
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


vector<vector<int>> AdjacencyMatrix::multMatrix(const vector<vector<int>>& matrix)
{
	vector<vector<int>> multedMatrix(this->size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			multedMatrix[i][j] = calcCell(matrix, i, j);
		}
	}

	return multedMatrix;
}


int AdjacencyMatrix::calcCell(const vector<vector<int>>& matrix, int row, int col)
{
	int cellVal = 0;

	for (int i = 0; i < size; i++)
	{

		cellVal += graph[row][i] * matrix[i][col];
	}

	return cellVal;
}