
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
	bool isValid = !(v<1 || u<1 || v>vertexNum || u>vertexNum);

	return isValid;
}

bool isAlgNumValid(int algNum)
{
	bool isValid = algNum >= 1 && algNum <= 4;

	return isValid;
}

/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////

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

			if (!onlySmalldegre || G.isVertDegreSmall(neighborOfI)) // potianial BUG 
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

		return nullptr;
	}
}

void main(int argc, char* argv[]) {

	string fileName = argv[1]; 


	ifstream infile(fileName);
	if (!infile)
	{
		cout << "invalid input." << endl;
		exit(1);
	}

	int numOfAlgo;
	//file >> noskipws; // avoid skipping spaces
	infile >> numOfAlgo;

	if (!isAlgNumValid(numOfAlgo))
	{
		cout << "invalid input." << endl;
		infile.close();
		exit(1);
	}

	AdjacencyList* G = nullptr;
	AdjacencyMatrix* G2 = nullptr;
	
	int numOfVert;
	infile >> numOfVert;




	if (numOfAlgo == 1 || numOfAlgo == 3)
	{
		G = new AdjacencyList(numOfVert);
	}
	else if (numOfAlgo == 2)
	{
		G2 = new AdjacencyMatrix(numOfVert);
	}
	else if(numOfAlgo == 4)
	{
		G = new AdjacencyList(numOfVert);
		G2 = new AdjacencyMatrix(numOfVert);

	}
	else
	{
		cout << "invalid input." << endl;
		infile.close();
		exit(1);
	}

	int vert, neigh;
	while (!infile.eof())
	{
		if (!infile.good())
		{
			cout << "invalid input." << endl;
			infile.close();
			exit(1);
		}

		infile >> vert >> neigh;
		if (!isEdgeValid(vert, neigh, numOfVert))
		{
			cout << "invalid input." << endl;
			infile.close();
			exit(1);
		}

		if (numOfAlgo == 1 || numOfAlgo == 3 || numOfAlgo == 4)
		{
			G->addEdge(vert, neigh);
		}
		else
		{
			G2->addEdge(vert, neigh);
		}
	}

	infile.close();


	string fileNameRes = argv[2];

	ofstream infileRes(fileNameRes);
	if (!infileRes)
	{
		cout << "invalid input." << endl;
		exit(1);
	}

	switch (numOfAlgo)
	{
	case 1:
	{
		list<int>* adj12 = alg1Outside(*G);
		infileRes << "Algo 1 res:" << endl;
		if (adj12 == nullptr)
		{
			infileRes << "NO";
		}
		for (auto it = adj12->begin(); it != adj12->end(); it++)
		{
			infileRes << *it << ", ";
		}
	}
	
	case 2:
	{
		list<int>* adj = alg2(*G2);
		infileRes << "Algo 2 res:" << endl;
		if (adj == nullptr)
		{
			infileRes << "NO";
		}
		for (auto it = adj->begin(); it != adj->end(); it++)
		{
			infileRes << *it << ", ";
		}
	}
	
	case 3:
	{
		list<int>* adj33 = alg3(*G);
		infileRes << "Algo 3 res:" << endl;
		if (adj33 == nullptr)
		{
			infileRes << "NO";
		}
		for (auto it = adj33->begin(); it != adj33->end(); it++)
		{
			infileRes << *it << ", ";
		}
	}
		
	case 4:
	{
		list<int>* adj1 = alg1Outside(*G);
		list<int>* adj2 = alg2(*G2);
		list<int>* adj3 = alg3(*G);
		infileRes << "Algo 1 res:" << endl;
		if (adj1 == nullptr)
		{
			infileRes << "NO";
		}
		for (auto it = adj1->begin(); it != adj1->end(); it++)
		{
			infileRes << *it << ", ";
		}
		infileRes << "Algo 2 res:" << endl;
		if (adj2 == nullptr)
		{
			infileRes << "NO";
		}
		for (auto it = adj2->begin(); it != adj2->end(); it++)
		{
			infileRes << *it << ", ";
		}
		infileRes << "Algo 3 res:" << endl;
		if (adj3 == nullptr)
		{
			infileRes << "NO";
		}
		for (auto it = adj3->begin(); it != adj3->end(); it++)
		{
			infileRes << *it << ", ";
		}
	}
		
	default:
		break;
	}	

	infileRes.close();
	/*/////////////////////////////////////////////////////////////////////////////
	Arbel up
	Shani down
	*//////////////////////////////////////////////////////////////////////////////

//	AdjacencyMatrix matrix(3);
//	matrix.addEdge(1, 2);
//	matrix.addEdge(2, 3);
//	//matrix.addEdge(3, 1);
//
//
//	list<int>* adj = alg2(matrix);
//	if (adj == nullptr)
//	{
//		cout << "shani you are the Queen" << std::endl;
//
//	}
//	else
//	{
//
//	
//	for (auto it = adj->begin(); it != adj->end(); it++)
//	{
//		cout << *it << std::endl;
//	}
//}
//
//
//	AdjacencyList lst(3);
//	lst.addEdge(1, 2);
//	lst.addEdge(2, 3);
//	//lst.addEdge(3, 1);
//
//	list<int>* adj2 = alg1Outside(lst);
//	if (adj2 == nullptr)
//	{
//		cout << "shani you are the Queen" << std::endl;
//
//	}
//	else
//	{
//
//	
//	for (auto it = adj2->begin(); it != adj2->end(); it++)
//	{
//		cout << *it << std::endl;
//	}
//}

	//shani branch
}

/*/////////////////////////////////////////////////////////////////////////////
Arbel up
Shani down
*//////////////////////////////////////////////////////////////////////////////