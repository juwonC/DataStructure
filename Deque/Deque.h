#pragma once

#include <string>

struct Element
{
	int value;
	Element* pNext{ nullptr };
	Element* pPrev{ nullptr };
};

class Deque
{
private:
	int count;
	Element* pFront;
	Element* pRear;

public:
	void Initialize(Deque& deque);
	void UserInput(Deque& deque, std::string input);
	void Push_front(Deque& deque, int value);
	void Push_back(Deque& deque, int value);
	void Pop_front(Deque& deque);
	void Pop_back(Deque& deque);
};

