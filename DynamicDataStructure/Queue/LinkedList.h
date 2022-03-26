#pragma once
#include "Queue.h"

enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

struct QueueList
{
	Queue* pHead = nullptr;
	Queue* pTail = nullptr;
};

void PrintInfo();
void PrintQueue(QueueList& list);
Queue* Enqueue(QueueList& list, int value);
bool Dequeue(QueueList& list);
void ProcessUserInput(QueueList& list);