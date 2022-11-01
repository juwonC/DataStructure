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

struct AdjacencyListGraph
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

AdjacencyListGraph* CreateAdjacecnyListGraph()
{
	AdjacencyListGraph* graph = new AdjacencyListGraph();

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

void DeleteGraph(AdjacencyListGraph* graph)
{
	while(graph->pVertices != nullptr)
	{
		Vertex* vertices = graph->pVertices->pNext;

		DeleteVertex(graph->pVertices);

		graph->pVertices = vertices;
	}

	delete graph;
}

void AddVertex(AdjacencyListGraph* graph, Vertex* vertex)
{
	Vertex* vertexList = graph->pVertices;

	if (vertexList == nullptr)
	{
		graph->pVertices = vertex;
	}
	else
	{
		while (vertexList->pNext != nullptr)
		{
			vertexList = vertexList->pNext;
		}

		vertexList->pNext = vertex;
	}

	graph->size++;
}

void AddEdge(Vertex* vertex, Edge* edge)
{
	if (vertex->pAdjacencyList == nullptr)
	{
		vertex->pAdjacencyList = edge;
	}
	else
	{
		Edge* edgeList = vertex->pAdjacencyList;

		while (edgeList->pNext != nullptr)
		{
			edgeList = edgeList->pNext;
		}

		edgeList->pNext = edge;
	}
}

void PrintGraph(AdjacencyListGraph* graph)
{
	Vertex* v = nullptr;
	Edge* e = nullptr;

	if ((v = graph->pVertices) == nullptr)
	{
		return;
	}

	std::cout << "Vertex Count : " << graph->size << std::endl;

	while (v != nullptr)
	{
		std::cout << v->value << " : ";

		if ((e = v->pAdjacencyList) == nullptr)
		{
			v = v->pNext;
			std::cout << std::endl;
			continue;
		}

		while (e != nullptr)
		{
			std::cout << e->pDestination->value << " ";
			e = e->pNext;
		}

		std::cout << std::endl;

		v = v->pNext;
	}

	std::cout << std::endl;
}

int main()
{
	std::cout << "AdjacencyListGraph" << std::endl;
	std::cout << "---------------------" << std::endl;

	AdjacencyListGraph* myGraph = CreateAdjacecnyListGraph();

	Vertex* v1 = CreateVertex(1);
	Vertex* v2 = CreateVertex(2);
	Vertex* v3 = CreateVertex(3);
	Vertex* v4 = CreateVertex(4);
	Vertex* v5 = CreateVertex(5);

	AddVertex(myGraph, v1);
	AddVertex(myGraph, v2);
	AddVertex(myGraph, v3);
	AddVertex(myGraph, v4);
	AddVertex(myGraph, v5);

	AddEdge(v1, CreateEdge(v1, v2));
	AddEdge(v1, CreateEdge(v1, v3));
	AddEdge(v1, CreateEdge(v1, v4));
	AddEdge(v1, CreateEdge(v1, v5));

	AddEdge(v2, CreateEdge(v2, v1));
	AddEdge(v2, CreateEdge(v2, v3));
	AddEdge(v2, CreateEdge(v2, v5));

	AddEdge(v3, CreateEdge(v3, v1));
	AddEdge(v3, CreateEdge(v3, v2));

	AddEdge(v4, CreateEdge(v4, v1));
	AddEdge(v4, CreateEdge(v4, v5));

	AddEdge(v5, CreateEdge(v5, v1));
	AddEdge(v5, CreateEdge(v5, v2));
	AddEdge(v5, CreateEdge(v5, v4));

	PrintGraph(myGraph);

	DeleteGraph(myGraph);
}