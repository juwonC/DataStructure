#include <cstring>
#include <iostream>
#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster;

    strcpy_s(pNew->name, NAME_LENGTH, name);
    pNew->hp = hp;
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

int GetCountMonsterList(const MonsterList& list)
{
    Monster* p = list.pHead;
    int count{};

    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }

    return count;
}

void PrintMonsterList(const MonsterList& list)
{
    Monster* p = list.pHead;

    while (p != nullptr)
    {
        std::cout << p->name << " " << p->hp << std::endl;

        p = p->pNext;
    }
}

void PrintMonsterListRecursive(Monster* monster)
{
    // base
    if (monster == nullptr)
    {
        return;
    }

    // recursive
    std::cout << monster->name << " : " << monster->hp << std::endl;

    PrintMonsterListRecursive(monster->pNext);
}

