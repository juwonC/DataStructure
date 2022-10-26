#include <iostream>

struct Vertex
{
	int value;

	Vertex* pNext;
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

	Vertex* vertices;
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
	graph->vertices = nullptr;

	return graph;
}

int main()
{
	std::cout << "AdjacencyListGraph" << std::endl;


}