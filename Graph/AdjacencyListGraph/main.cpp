#include <iostream>

struct Vertex
{
	int value;

	Vertex* pNext;
	struct Edge* pAdjacencyList;
};

struct Edge
{
	Edge* pNext;

	Vertex* pSource;
	Vertex* pDestination;
};

struct AdjacecnyListGraph
{
	int size;

	Vertex* pVertices;
};

Vertex* CreateVertex(int vertex)
{
	Vertex* node = new Vertex();

	node->value = vertex;
	node->pNext = nullptr;

	return node;
}

Edge* CreateEdge(Vertex* u, Vertex* v)
{
	Edge* edge = new Edge();

	edge->pNext = nullptr;
	edge->pSource = u;
	edge->pDestination = v;

	return edge;
}

AdjacecnyListGraph* CreateAdjacecnyListGraph()
{
	AdjacecnyListGraph* graph = new AdjacecnyListGraph();

	graph->size = 0;
	graph->pVertices = nullptr;

	return graph;
}

void DeleteEdge(Edge* edge)
{
	delete edge;
}

void DeleteVertex(Vertex* vertex)
{
	while (vertex->pAdjacencyList != nullptr)
	{
		Edge* edge = vertex->pAdjacencyList->pNext;
		
		DeleteEdge(vertex->pAdjacencyList);

		vertex->pAdjacencyList = edge;
	}

	delete vertex;
}

void DeleteGraph(AdjacecnyListGraph* graph)
{
	while(graph->pVertices != nullptr)
	{
		Vertex* vertices = graph->pVertices->pNext;

		DeleteVertex(graph->pVertices);

		graph->pVertices = vertices;
	}

	delete graph;
}

int main()
{
	std::cout << "AdjacencyListGraph" << std::endl;


}