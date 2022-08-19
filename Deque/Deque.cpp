#include <iostream>
#include "Deque.h"

void Deque::Initialize(Deque& deque)
{
	deque.count = 0;
	deque.pFront = deque.pRear = nullptr;
}

void Deque::UserInput(Deque& deque, std::string input)
{
    if (input == "push_front")
    {
        int value;

        std::cin >> value;

        Push_front(deque, value);
    }
    else if (input == "push_back")
    {
        int value;

        std::cin >> value;

        Push_back(deque, value);
    }
    else if (input == "pop_front")
    {
        Pop_front(deque);
    }
    else if (input == "pop_back")
    {
        Pop_back(deque);
    }
    else
    {
        return;
    }
}

void Deque::Push_front(Deque& deque, int value)
{
    Element* element = new Element;
    element->value = value;
    element->pPrev = nullptr;

    if (element == nullptr)
    {
        return;
    }

    if (deque.count == 0)
    {
        deque.pRear = element;
    }
    else
    {
        element->pNext = deque.pFront;
        deque.pFront->pPrev = element;
    }
    deque.pFront = element;

    deque.count++;
}

void Deque::Push_back(Deque& deque, int value)
{
    Element* element = new Element;
    element->value = value;
    element->pNext = nullptr;

    if (element == nullptr)
    {
        return;
    }

    if (deque.count == 0)
    {
        deque.pFront = element;
    }
    else
    {
        element->pPrev = deque.pRear;
        deque.pRear->pNext = element;
    }
    deque.pRear = element;

    deque.count++;
}

void Deque::Pop_front(Deque& deque)
{
    if (deque.count == 0)
    {
        std::cout << -1 << '\n';
        return;
    }

    Element* element = deque.pFront;

    std::cout << element->value << '\n';

    deque.pFront = element->pNext;

    delete element;
    deque.count--;
}

void Deque::Pop_back(Deque& deque)
{
    if (deque.count == 0)
    {
        std::cout << -1 << '\n';
        return;
    }

    Element* element = deque.pRear;

    std::cout << element->value << '\n';

    deque.pRear = element->pPrev;

    delete element;
    deque.count--;
}

void Deque::GetSize(Deque& deque)
{
}

void Deque::CheckEmpty(Deque& deque)
{
}

void Deque::GetFront(Deque& deque)
{
}

void Deque::GetBack(Deque& deque)
{
}
