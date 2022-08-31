#include <iostream>

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

int main()
{
	DoubleLinked myList;


}