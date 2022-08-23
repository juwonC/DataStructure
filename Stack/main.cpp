#include <iostream>
#include <string>

const int STACK_SIZE = 100;

struct Stack
{
	int container[STACK_SIZE]{};
	int topIndex = -1;
};

void UserInput(Stack& s, std::string input);
void Push(Stack& s, int value);
void Pop(Stack& s);
void Size(Stack& s);
void Empty(Stack& s);
void Top(Stack& s);
void Print(Stack& s);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Stack myStack;
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string input;

		std::cin >> input;

		UserInput(myStack, input);
	}
}

void UserInput(Stack& s, std::string input)
{
	if (input == "push")
	{
		int value;

		std::cin >> value;
		
		Push(s, value);
	}
	else if (input == "pop")
	{
		Pop(s);
	}
	else if (input == "size")
	{
		Size(s);
	}
	else if (input == "empty")
	{
		Empty(s);
	}
	else if (input == "top")
	{
		Top(s);
	}
	else if (input == "print")
	{
		Print(s);
	}
	else
	{
		return;
	}
}

void Push(Stack& s, int value)
{
	if (s.topIndex >= STACK_SIZE - 1)
	{
		std::cout << "Stack is full!" << '\n';
		return;
	}

	s.container[++s.topIndex] = value;
}

void Pop(Stack& s)
{
	if (s.topIndex < 0)
	{
		std::cout << "Stack is empty!" << '\n';
		return;
	}

	std::cout << s.container[s.topIndex--] << '\n';
}

void Size(Stack& s)
{
	std::cout << s.topIndex + 1 << '\n';
}

void Empty(Stack& s)
{
	if (s.topIndex < 0) // Empty stack
	{
		std::cout << 1 << '\n';
	}
	else
	{
		std::cout << 0 << '\n';
	}
}

void Top(Stack& s)
{
	if (s.topIndex < 0)
	{
		std::cout << "Stakc is empty!" << '\n';
		return;
	}
	
	std::cout << s.container[s.topIndex] << '\n';
}

void Print(Stack& s)
{
	for (int i = s.topIndex; i >= 0; i--)
	{
		std::cout << s.container[i] << '\n';
	}
	std::cout << '\n';
}
