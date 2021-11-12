
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <iostream>

using namespace std;

list<int>* alg2(AdjacencyMatrix& G)
{
	vector<vector<int>>* GSqured2 = G.multMatrix(G);
	vector<vector<int>>* GSqured3 = G.multMatrix(*GSqured2);

	for (int i = 0; i < G.getSize(); i++)
	{
		if ((*GSqured3)[i][i] >= 1)
		{
			for (int j = 0; j < G.getSize(); j++)
			{
				if ((*GSqured2)[i][j] >= 1)
				{
					for (int k = 0; k < G.getSize(); k++)
					{
						if (G.isNeighbor(i + 1, k + 1)) // potianial BUG neib oposite
						{
							if (G.isNeighbor(k + 1, j + 1)) // potianial BUG neib oposite
							{
								list<int>* triangleVertices = new list<int>;
								triangleVertices->push_back(i + 1);
								triangleVertices->push_back(j + 1);
								triangleVertices->push_back(k + 1);

								delete GSqured2;
								delete GSqured3;

								return triangleVertices;
							}
						}
					}
				}
			}
		}
	}

	delete GSqured2;
	delete GSqured3;
	return nullptr;
}

list<int>* alg3(AdjacencyList& G)
{
	//stage 1:
	// shani algo
}


/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////

list<int>* alg1(AdjacencyList& G)
{
	AdjacencyMatrix Gmatrix(G);

	for (int i = 0; i < G.getSize(); i++)
	{
		list<int> vertINeighbors = G.getNeighbors(i + 1);

		for (auto it = vertINeighbors.begin(); it != vertINeighbors.end(); it++)
		{
			int neighborOfI = *it;
			list<int> vertNeighborsOfNeighborI = G.getNeighbors(neighborOfI);

			for (auto it2 = vertNeighborsOfNeighborI.begin(); it2 != vertNeighborsOfNeighborI.end(); it2++)
			{
				int neighborOfneighbor = *it2;

				if (Gmatrix.isNeighbor(neighborOfneighbor, i + 1))
				{
					list<int>* triangleVertices = new list<int>;
					triangleVertices->push_back(i + 1);
					triangleVertices->push_back(neighborOfI);
					triangleVertices->push_back(neighborOfneighbor);

					return triangleVertices;
				}
			}
		}

		return nullptr;
	}
}

void main() {


/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////
	
	AdjacencyMatrix matrix(3);
	matrix.addEdge(1, 2);
	matrix.addEdge(2, 3);
	matrix.addEdge(3, 1);


	list<int>* adj = alg2(matrix);
	for (auto it = adj->begin(); it != adj->end(); it++)
	{
		cout << *it << std::endl;
	}

	//shani branch
}

/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////