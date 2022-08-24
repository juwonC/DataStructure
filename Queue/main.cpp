#include <iostream>

const int QUEUE_SIZE = 100;

struct Queue
{
	int container[QUEUE_SIZE]{};

	int pHead{ -1 };
	int pTail{ -1 };
};

void UserInput(std::string input);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Queue myQueue;

	while (true)
	{
		std::string input;

		std::cin >> input;

		UserInput(input);

		if (input == "quit")
		{
			break;
		}
	}
}

void UserInput(std::string input)
{

}
