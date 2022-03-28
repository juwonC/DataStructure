#pragma once

const int NAME_LENGTH{ 15 };

// self referenced structure
struct Monster
{
	char name[NAME_LENGTH];
	int hp;

	Monster* pNext;
};