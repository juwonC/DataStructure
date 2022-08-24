#include <iostream>
#include <string>

const int QUEUE_SIZE = 100;

struct Queue
{
	int container[QUEUE_SIZE]{};

	int pHead{ -1 };
	int pTail{ -1 };
};

void UserInput(Queue& q, std::string input);
void Enqueue(Queue& q, int value);
void Dequeue(Queue& q);
void GetSize(Queue& q);
void CheckEmpty(Queue& q);
void Print(Queue& q);

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

		UserInput(myQueue, input);

		if (input == "quit")
		{
			break;
		}
	}
}

void UserInput(Queue& q, std::string input)
{
	if (input == "enqueue")
	{
		int value;

		std::cin >> value;
		
		Enqueue(q, value);
	}
	else if (input == "dequeue")
	{
		Dequeue(q);
	}
	else if (input == "size")
	{
		GetSize(q);
	}
	else if (input == "empty")
	{
		CheckEmpty(q);
	}
	else if (input == "print")
	{
		Print(q);
	}
	else
	{
		return;
	}
}

void Enqueue(Queue& q, int value)
{
	if (q.pTail == QUEUE_SIZE - 1)
	{
		std::cout << "Queue is full" << '\n';
		return;
	}

	q.container[++q.pTail] = value;
}

void Dequeue(Queue& q)
{
	if (q.pHead == q.pTail)
	{
		std::cout << "Queue is empty" << '\n';
		return;
	}

	std::cout << q.container[++q.pHead] << '\n';
}

void GetSize(Queue& q)
{
	std::cout << q.pTail - q.pHead << '\n';
}

void CheckEmpty(Queue& q)
{
	if (q.pHead == q.pTail)
	{
		std::cout << 1 << '\n';
	}
	else
	{
		std::cout << 0 << '\n';
	}
}

void Print(Queue& q)
{
	for (int i = 0; i < QUEUE_SIZE - 1; i++)
	{
		if (i <= q.pHead || i > q.pTail)
		{
			std::cout << " ";
		}
		else
		{
			std::cout << q.container[i] << " ";
		}
	}
	std::cout << '\n';
}
