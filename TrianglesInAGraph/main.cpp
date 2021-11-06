
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


list<int>* alg2(AdjacencyMatrix& G)
{
	AdjacencyMatrix* GSqured2 = G.mult(G);

	AdjacencyMatrix* GSqured3 = GSqured2.mult(G);

	list<int>* triangleVertices = nullptr;

	for (int i = 0; i < G.getSize(); i++)
	{
		if (GSqured3[i][i] >= 1)
		{
			for (int j = 0; j < G.getSize(); j++)
			{
				if (GSqured2[i][j] >= 1)
				{
					for (int k = 0; k < G.getSize(); k++)
					{
						if (G[i][k] >= 1)
						{
							if (G[k][j] >= 1)
							{
								triangleVertices = new list<int>;
								triangleVertices->push_back(i);
								triangleVertices->push_back(j);
								triangleVertices->push_back(k);
								break;
							}
						}
					}
				}
			}
		}
	}

	return triangleVertices;
}


void main() {



}