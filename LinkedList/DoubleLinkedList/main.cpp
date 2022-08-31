#include <iostream>
#include <string.h>

struct Node
{
	char name[10];
	int value;

	Node* pNext;
	Node* pPrev;
};

struct DoubleLinked
{
	Node* pHead = nullptr;
	Node* pTail = nullptr;
};

Node* CreateNode(DoubleLinked& list, const char* name, const int num);
int GetCountList(DoubleLinked& list);
void PrintList(DoubleLinked& list);
Node* FindNode(DoubleLinked& list, const char* name);
void DeleteList(DoubleLinked& list);
bool DeleteNode(DoubleLinked& list, const char* name);

int main()
{
	DoubleLinked myList;

    CreateNode(myList, "A", 1);
    CreateNode(myList, "B", 2);
    CreateNode(myList, "C", 3);
    CreateNode(myList, "D", 4);

    std::cout << GetCountList(myList) << std::endl;
    PrintList(myList);
    std::cout << std::endl;

    DeleteNode(myList, "A");
    std::cout << GetCountList(myList) << std::endl;
    PrintList(myList);
    std::cout << std::endl;

    DeleteNode(myList, "C");
    std::cout << GetCountList(myList) << std::endl;
    PrintList(myList);
}

Node* CreateNode(DoubleLinked& list, const char* name, const int num)
{
    Node* element = new Node();

    strcpy_s(element->name, 10, name);
    element->value = num;
    element->pNext = nullptr;
    element->pPrev = nullptr;

    if (list.pTail == nullptr)
    {
        list.pHead = element;
        list.pTail = element;
    }
    else
    {
        element->pPrev = list.pTail;
        list.pTail->pNext = element;
        list.pTail = element;
    }

    return element;
}

int GetCountList(DoubleLinked& list)
{
    Node* element = list.pHead;

    int count{};

    while (element != nullptr)
    {
        count++;
        element = element->pNext;
    }

    return count;
}

void PrintList(DoubleLinked& list)
{
    Node* element = list.pHead;

    while (element != nullptr)
    {
        std::cout << element->name << " " << element->value << std::endl;
        element = element->pNext;
    }
}

Node* FindNode(DoubleLinked& list, const char* name)
{
    Node* result = nullptr;
    Node* element = list.pHead;

    while (element != nullptr)
    {
        if (strcmp(element->name, name) == 0)
        {
            return element;
        }

        element = element->pNext;
    }

    return nullptr;
}

void DeleteList(DoubleLinked& list)
{
    Node* element = list.pHead;
    Node* next;

    while (element != nullptr)
    {
        next = element->pNext;
        delete element;

        element = next;
    }

    list.pHead = nullptr;
    list.pTail = nullptr;
}

bool DeleteNode(DoubleLinked& list, const char* name)
{
    Node* element = FindNode(list, name);

    if (element != nullptr)
    {
        if (element->pPrev == nullptr)
        {
            list.pHead = element->pNext;
        }
        else
        {
            element->pPrev->pNext = element->pNext;
        }

        if (element->pNext == nullptr)
        {
            list.pTail = element->pPrev;
        }
        else
        {
            element->pNext->pPrev = element->pPrev;
        }

        delete element;

        return true;
    }

    return false;
}