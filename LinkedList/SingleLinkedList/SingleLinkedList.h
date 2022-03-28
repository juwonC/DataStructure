#pragma once
#include "Monster.h"

struct MonsterList
{
	Monster* pHead;
	Monster* pTail;
};

Monster* CreateMonster(MonsterList& list, const char* name, const int hp);
int GetCountMonsterList(const MonsterList& list);
void PrintMonsterList(const MonsterList& list);
void PrintMonsterListRecursive(Monster* monster);