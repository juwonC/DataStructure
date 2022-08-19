#include <iostream>
#include <string>
#include "Deque.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Deque myDeque;
	int n;

	myDeque.Initialize(myDeque);

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string input;

		std::cin >> input;

		myDeque.UserInput(myDeque, input);
	}
}