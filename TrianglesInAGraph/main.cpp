#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <iostream>
#include <istream>
#include <fstream>

using namespace std;
list<int>* alg1Outside(AdjacencyList& G);
list<int>* alg1Inside(AdjacencyList& G, bool onlySmalldegre);

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
					if (G.isNeighbor(j + 1, i + 1))
					{
						for (int k = 0; k < G.getSize(); k++)
						{
							if (G.isNeighbor(i + 1, k + 1))
							{
								if (G.isNeighbor(k + 1, j + 1))
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
	}

	delete GSqured2;
	delete GSqured3;
	return nullptr;
}

list<int>* alg3(AdjacencyList& G)
{
	//stage 1:
	list<int>* circle = alg1Inside(G, true);

	if (circle == nullptr)
	{
		//stage 2:
		AdjacencyMatrix highDegGraph = AdjacencyMatrix(G, G.getDegArr());
		circle = alg2(highDegGraph);
	}

	return circle;
}

bool isEdgeValid(int v, int u, int vertexNum)
{
	bool isValid = !(v<1 || u<1 || v>vertexNum || u>vertexNum) && v != u;

	return isValid;
}

bool isAlgNumValid(int algNum)
{
	bool isValid = algNum >= 1 && algNum <= 4;

	return isValid;
}

void fileError(ifstream& infile, ofstream& outfileRes)
{
	outfileRes << "invalid input." << endl;
	infile.close();
	outfileRes.close();
	exit(1);
}


void writeResToFile(ofstream& infileRes, list<int>* adj, int algoNum)
{
	if (adj == nullptr)
	{
		infileRes << "NO" << endl;
		return;
	}

	infileRes << "Algorithm " << algoNum << " result:" << endl;
	
	for (auto it = adj->begin(); it != adj->end(); it++)
	{
		infileRes << *it << " ";
	}

	infileRes << endl;
}

list<int>* alg1Outside(AdjacencyList& G)
{
	return alg1Inside(G, false);
}

list<int>* alg1Inside(AdjacencyList& G, bool onlySmalldegre)
{
	AdjacencyMatrix Gmatrix(G);

	for (int i = 0; i < G.getSize(); i++)
	{
		list<int> vertINeighbors = G.getNeighbors(i + 1);

		for (auto it = vertINeighbors.begin(); it != vertINeighbors.end(); it++)
		{
			int neighborOfI = *it;

			if (!onlySmalldegre || G.isVertDegreSmall(neighborOfI))
			{
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
		}
	}
	
	return nullptr;
}

void main(int argc, char* argv[]) {

	string fileName = argv[1]; 
	ifstream infile(fileName);
	string fileNameRes = argv[2];
	ofstream infileRes(fileNameRes);

	if (!infile || !infileRes)
	{
		infileRes << "invalid input." << endl;
		exit(1);
	}

	int numOfAlgo;
	infile >> numOfAlgo;

	if (!isAlgNumValid(numOfAlgo))
	{
		fileError(infile, infileRes);
	}

	AdjacencyList* G = nullptr;
	AdjacencyMatrix* G2 = nullptr;
	int numOfVert;

	infile >> numOfVert;

	if (numOfAlgo == 1 || numOfAlgo == 3 || numOfAlgo == 4)
	{
		G = new AdjacencyList(numOfVert);
	}

	if (numOfAlgo == 2 || numOfAlgo == 4)
	{
		G2 = new AdjacencyMatrix(numOfVert);
	}

	if (!infile.good())
	{
		fileError(infile, infileRes);
	}

	int vert, neigh;

	while (infile >> vert >> neigh)
	{
		if (!isEdgeValid(vert, neigh, numOfVert))
		{
			fileError(infile, infileRes);
		}

		if (numOfAlgo == 1 || numOfAlgo == 3 || numOfAlgo == 4)
		{
			G->addEdge(vert, neigh);
		}
		
		if (numOfAlgo == 2 || numOfAlgo == 4)
		{
			G2->addEdge(vert, neigh);
		}
	}

	infile.close();

	switch (numOfAlgo)
	{
	case 1:
	{
		list<int>* adj1 = alg1Outside(*G);
		writeResToFile(infileRes, adj1, numOfAlgo);
		break;
	}

	case 2:
	{
		list<int>* adj2 = alg2(*G2);
		writeResToFile(infileRes, adj2, numOfAlgo);
		break;
	}

	case 3:
	{
		list<int>* adj3 = alg3(*G);
		writeResToFile(infileRes, adj3, numOfAlgo);
		break;
	}
	case 4:
	{
		list<int>* adj1 = alg1Outside(*G);
		list<int>* adj2 = alg2(*G2);
		list<int>* adj3 = alg3(*G);

		writeResToFile(infileRes, adj1, 1);
		writeResToFile(infileRes, adj2, 2);
		writeResToFile(infileRes, adj3, 3);

		break;
	}

	default:
		break;
	}

	infileRes.close();
}