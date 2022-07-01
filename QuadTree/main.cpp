#include <iostream>
#include "QuadTree.h"

int main()
{
	QuadTree qt(Point(0, 0), Point(8, 8));

	std::unique_ptr<Node> a = std::make_unique<Node>(Point(1, 1), 1);
	std::unique_ptr<Node> b = std::make_unique<Node>(Point(2, 2), 2);
	std::unique_ptr<Node> c = std::make_unique<Node>(Point(3, 3), 3);
	std::unique_ptr<Node> d = std::make_unique<Node>(Point(4, 4), 4);

	qt.Insert(a.get());
	qt.Insert(b.get());
	qt.Insert(c.get());
	qt.Insert(d.get());

	auto result = qt.Search(Point(2, 2));

	if (result)
	{
		std::cout << result->position.x << ", " << result->position.y <<
			" : " << result->data << std::endl;
	}
	else
	{
		std::cout << "Not Found" << std::endl;
	}
}