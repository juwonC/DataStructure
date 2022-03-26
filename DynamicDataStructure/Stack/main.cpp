#include <iostream>

struct Stack
{
	int value;

	Stack* pNext;
};

struct StackList
{
	Stack* pTop = nullptr;
};

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

void PrintInfo();
void PrintStack(StackList& list);
Stack* Push(StackList& list, int value);
bool Pop(StackList& list);
void ProcessUserInput(StackList& list);

int main()
{
	StackList myStack{};

	PrintInfo();
	ProcessUserInput(myStack);
}

void PrintInfo()
{
	std::cout << "[STACK]" << std::endl <<
				 "[1] Push" << std::endl <<
				 "[2] Pop" << std::endl <<
				 "[3] Exit" << std::endl;
	std::cout << "------------" << std::endl;
}

void PrintStack(StackList& list)
{
	Stack* p = list.pTop;
	std::cout << "[STACK]" << std::endl;

	if (p == nullptr)
	{
		std::cout << "EMPTY" << std::endl;
	}

	while(p != nullptr)
	{
		std::cout << p->value << std::endl;

		p = p->pNext;
	}

	std::cout << "--------------";
}

Stack* Push(StackList& list, int value)
{
	Stack* pNew = new Stack;

	pNew->value = value;

	pNew->pNext = list.pTop;
	list.pTop = pNew;

	return pNew;
}

bool Pop(StackList& list)
{
	Stack* pCurrent = list.pTop;

	if (pCurrent == nullptr)
	{
		return false;
	}

	list.pTop = pCurrent->pNext;

	std::cout << pCurrent->value << " Pop!" << std::endl;
	delete pCurrent;

	return false;
}

void ProcessUserInput(StackList& list)
{
	int command{};
	bool isExit{ false };

	while (true)
	{
		PrintStack(list);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
			{
				int value;
				std::cout << "  push value > ";
				std::cin >> value;
				Push(list, value);
				break;
			}

			case POP:
				Pop(list);
				break;

			case EXIT:
				isExit = true;
				break;

			default:
				std::cout << "잘못된 명령어 입니다." << std::endl;
				break;
		}

		if (isExit)
		{
			break;
		}
	}
}