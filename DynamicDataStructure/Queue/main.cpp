#include <iostream>

struct Queue
{
	int value;

	Queue* pNext;
};

struct QueueList
{
	Queue* pHead = nullptr;
	Queue* pTail = nullptr;
};

enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

void PrintInfo();
void PrintQueue(QueueList& list);
Queue* Enqueue(QueueList& list, int value);
bool Dequeue(QueueList& list);
void ProcessUserInput(QueueList& list);

int main()
{
	QueueList myQueue{};

	PrintInfo();
	ProcessUserInput(myQueue);
}

void PrintInfo()
{
	std::cout << "[QUEUE]" << std::endl <<
		"[1] Enqueue" << std::endl <<
		"[2] Dequeue" << std::endl <<
		"[3] Exit" << std::endl;
	std::cout << "------------" << std::endl;
}

void PrintQueue(QueueList& list)
{
	Queue* p = list.pHead;
	std::cout << "[Queue]" << std::endl;

	if (p == nullptr)
	{
		std::cout << "EMPTY" << std::endl;
	}

	while (p != nullptr)
	{
		std::cout << p->value << " ";

		p = p->pNext;
	}
	std::cout << std::endl << "--------------";
}

Queue* Enqueue(QueueList& list, int value)
{
	Queue* pNew = new Queue;

	pNew->value = value;
	pNew->pNext = nullptr;

	if (list.pTail == nullptr)
	{
		list.pHead = pNew;
	}
	else
	{
		list.pTail->pNext = pNew;
	}
	list.pTail = pNew;

	return pNew;
}

bool Dequeue(QueueList& list)
{
	Queue* pCurrent = list.pHead;

	if (pCurrent == nullptr)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
	}
	else if (list.pHead == pCurrent)
	{
		list.pHead = pCurrent->pNext;
	}
	std::cout << pCurrent->value << " Dequeue!" << std::endl;
	delete pCurrent;

	return false;
}

void ProcessUserInput(QueueList& list)
{
	int command{};
	bool isExit{ false };

	while (true)
	{
		PrintQueue(list);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE:
			{
				int value;
				std::cout << "  Enqueue value > ";
				std::cin >> value;
				Enqueue(list, value);
				break;
			}

			case DEQUEUE:
				Dequeue(list);
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