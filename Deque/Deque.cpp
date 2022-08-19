#include "Deque.h"

void Deque::Initialize(Deque& deque)
{
	deque.count = 0;
	deque.pFront = deque.pRear = nullptr;
}
