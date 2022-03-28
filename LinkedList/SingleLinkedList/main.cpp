#include <iostream>
#include "SingleLinkedList.h"

int main()
{
	MonsterList myList{};

	CreateMonster(myList, "Dragon", 90);
	CreateMonster(myList, "Ghost", 30);
	CreateMonster(myList, "Demon", 50);
	std::cout << GetCountMonsterList(myList) << std::endl;

	PrintMonsterList(myList);
}