#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyList& adjList) : AdjacencyMatrix(adjList.getSize())
{
	for (int i = 1; i <= size; i++)
	{
		for (auto it = adjList.getNeighbors(i).begin(); it != adjList.getNeighbors(i).end(); it++)
		{
			graph[i - 1][*it - 1] = 1;
		}
	}
}

AdjacencyMatrix::AdjacencyMatrix(int size) : graph(vector<vector<int>>(size)), size(size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			graph[i].push_back(0);
		}
	}
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyList& adjList, vector<int>& degArr) : AdjacencyMatrix(adjList.getSize())
{
	int highDeg = sqrt((double)adjList.getEdges());

	for (int i = 1; i <= size; i++)
	{
		for (auto it = adjList.getNeighbors(i).begin(); it != adjList.getNeighbors(i).end(); it++)
		{
			if (degArr[i - 1] >= highDeg)
			{
				graph[i - 1][*it - 1] = 1;
			}
		}
	}
}

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix& other)
{
	*this = other;
}


const AdjacencyMatrix& AdjacencyMatrix::operator=(const AdjacencyMatrix& other)
{
	if (this != &other)
	{
		size = other.size;
		graph = other.graph;
	}
	return *this;
}

AdjacencyMatrix::~AdjacencyMatrix()
{}

int AdjacencyMatrix::getSize()
{
	return size;
}

void AdjacencyMatrix::addEdge(int vert, int neigh) //function to add edge into the matrix
{			
	graph[vert - 1][neigh - 1] = 1;
}

bool AdjacencyMatrix::isNeighbor(int vert, int neigh)
{
	return graph[vert - 1][neigh - 1];
}

vector<int>& AdjacencyMatrix::getNeighbors(int vert)
{
	return graph[vert - 1];
}

const vector<int>& AdjacencyMatrix::operator[](int i) const 
{
	return graph[i];
}

vector<int>& AdjacencyMatrix::operator[](int i) 
{
	return graph[i];
}

vector<vector<int>>* AdjacencyMatrix::multMatrix(const vector<vector<int>>& matrix) const
{
	vector<vector<int>>* multedMatrix = new vector<vector<int>>(this->size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			(*multedMatrix)[i].push_back(calcCell(matrix, i, j));
		}
	}

	return multedMatrix;
}


int AdjacencyMatrix::calcCell(const vector<vector<int>>& matrix, int row, int col) const
{
	int cellVal = 0;

	for (int i = 0; i < size; i++)
	{
		int a = graph[row][i];
		int b = matrix[i][col];
		cellVal += (a * b);
	}

	return cellVal;
}

vector<vector<int>>* AdjacencyMatrix::multMatrix(const AdjacencyMatrix& matrix) const
{
	return multMatrix(matrix.graph);
}
