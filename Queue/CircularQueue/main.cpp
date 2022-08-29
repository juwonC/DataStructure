#include <iostream>
#include <string>

const int QUEUE_SIZE = 10;

struct Circular
{
	int container[QUEUE_SIZE];
	int head{};
	int tail{};
};

void UserInput(Circular& c, std::string input);
void Print(Circular& c);
void Push(Circular& c, int value);
void Pop(Circular& c);
void GetSize(Circular& c);
void CheckEmpty(Circular& c);
void GetFront(Circular& c);
void GetBack(Circular& c);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Circular myQueue;
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string input;

		std::cin >> input;

		UserInput(myQueue, input);
	}
}

void UserInput(Circular& c, std::string input)
{
	if (input == "print")
	{
		Print(c);
	}
	else if (input == "push")
	{
		int value;

		std::cin >> value;
		
		Push(c, value);
	}
	else if (input == "pop")
	{
		Pop(c);
	}
	else if (input == "size")
	{
		GetSize(c);
	}
	else if (input == "empty")
	{
		CheckEmpty(c);
	}
	else if (input == "front")
	{
		GetFront(c);
	}
	else if (input == "back")
	{
		GetBack(c);
	}
	else
	{
		return;
	}
}

void Print(Circular& c)
{
	int i = c.head;

	while (i != c.tail)
	{
		i = (i + 1) % QUEUE_SIZE;

		std::cout << c.container[i] << " ";
	}
	std::cout << '\n';
}

void Push(Circular& c, int value)
{
	if ((c.tail + 1) % QUEUE_SIZE == c.head)
	{
		std::cout << "Queue is full!" << '\n';
		return;
	}

	c.tail = (c.tail + 1) % QUEUE_SIZE;
	c.container[c.tail] = value;
}

void Pop(Circular& c)
{
	if (c.tail == c.head)
	{
		std::cout << "Queue is empty!" << '\n';
		return;
	}

	c.head = (c.head + 1) % QUEUE_SIZE;
	std::cout << c.container[c.head] << '\n';
}

void GetSize(Circular& c)
{
	std::cout << c.tail - c.head << '\n';
}

void CheckEmpty(Circular& c)
{
	if (c.head == c.tail)
	{
		std::cout << 1 << '\n';
	}
	else
	{
		std::cout << 0 << '\n';
	}
}

void GetFront(Circular& c)
{
	if (c.tail == c.head)
	{
		std::cout << "Queue is empty!" << '\n';
		return;
	}

	std::cout << c.container[c.head + 1] << '\n';
}

void GetBack(Circular& c)
{
	if (c.tail == c.head)
	{
		std::cout << "Queue is empty!" << '\n';
		return;
	}
	
	std::cout << c.container[c.tail] << '\n';
}
