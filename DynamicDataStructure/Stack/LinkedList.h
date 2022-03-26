#pragma once
#include "Stack.h"

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

struct StackList
{
	Stack* pTop = nullptr;
};

void PrintInfo();
void PrintStack(StackList& list);
Stack* Push(StackList& list, int value);
bool Pop(StackList& list);
void ProcessUserInput(StackList& list);