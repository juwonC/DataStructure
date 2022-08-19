#pragma once

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
};

