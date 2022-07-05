#include <iostream>
#include <vector>

// Max Heap
class Heap
{
	std::vector<int> mHeap;

public:
	void Insert(int value)
	{
		mHeap.push_back(value);

		int i = static_cast<int>(mHeap.size() - 1);
		int half = (i - 1) / 2;

		while (i != 0 && value > mHeap[half])
		{
			mHeap[i] = mHeap[half];
			mHeap[half] = value;
			i = half;
			half = (i - 1) / 2;
		}
	}

	void Print()
	{
		for (auto& e : mHeap)
		{
			std::cout << e << " ";
		}
	}
};



int main()
{
	Heap h;

	h.Insert(1);
	h.Insert(2);
	h.Insert(3);
	h.Insert(4);
	h.Insert(5);

	h.Print();
}