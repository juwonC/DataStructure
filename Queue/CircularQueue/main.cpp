#include <iostream>

const int QUEUE_SIZE = 10;

struct Circular
{
	int container[QUEUE_SIZE];
	int head{};
	int tail{};
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Circular myQueue;


}