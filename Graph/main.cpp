#include <iostream>
#include <vector>

void CreateGraph_1()
{
	struct Vertex
	{
		std::vector<Vertex*> edges;
	};

	std::vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);
}

int main()
{

}