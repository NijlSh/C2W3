#include "BubbleSort.h"

void BubbleSort::PrintCounters()
{
	std::cout << "??????????? ??????????." << std::endl;
	ISort::PrintCounters();
}

void BubbleSort::AbsoluteSort(std::vector<int>& arr, int size)
{
	bool end = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comparison_counter++;
			if (abs(arr[j]) > abs(arr[j + 1]))
			{
				swap_counter++;
				std::swap(arr[j], arr[j + 1]);
				end = false;
			}

		}
		if (end) 
			return;
	}
}

void BubbleSort::Sort(std::vector<int>& arr, int size)
{
	bool end = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comparison_counter++;
			if (arr[j] > arr[j + 1])
			{
				swap_counter++;
				std::swap(arr[j], arr[j + 1]);
				end = false;
			}

		}
		if (end)
			return;
	}
}