#include <iostream>

const int MAX_VERTEX = 10;

struct AdjaceneyMatrixGraph
{
	int count{};
	int vertices[MAX_VERTEX]{};
	int adjacencyMatrix[MAX_VERTEX][MAX_VERTEX]{};
};

void InsertVertex(AdjaceneyMatrixGraph& graph, int vertex)
{
	graph.vertices[graph.count++] = vertex;
}

void InsertEdges(AdjaceneyMatrixGraph& graph, int u, int v)
{
	graph.adjacencyMatrix[u][v] = 1;
	graph.adjacencyMatrix[v][u] = 1;	// remove for directed graph
}

void PrintGraph(AdjaceneyMatrixGraph graph)
{
	std::cout << "vertex count : " << graph.count << std::endl;

	for (int i = 0; i < graph.count; i++)
	{
		for (int j = 0; j < graph.count; j++)
		{
			std::cout << graph.adjacencyMatrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	AdjaceneyMatrixGraph myGraph;

	InsertVertex(myGraph, 1);
	InsertVertex(myGraph, 2);
	InsertVertex(myGraph, 3);
	InsertVertex(myGraph, 4);
	InsertVertex(myGraph, 5);

	InsertEdges(myGraph, 0, 1);
	InsertEdges(myGraph, 0, 2);
	InsertEdges(myGraph, 0, 3);
	InsertEdges(myGraph, 0, 4);

	InsertEdges(myGraph, 1, 2);
	InsertEdges(myGraph, 1, 4);

	InsertEdges(myGraph, 3, 4);

	PrintGraph(myGraph);
}