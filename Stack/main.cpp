#include <iostream>

const int STACK_SIZE = 10;

struct Stack
{
	int container[STACK_SIZE]{};
	int topIndex = -1;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Stack myStack;


}