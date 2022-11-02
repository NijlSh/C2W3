#include "SelectionSort.h"

void SelectionSort::PrintCounters()
{
	std::cout << "Сортировка выбором." << std::endl;
	ISort::PrintCounters();
}

void SelectionSort::AbsoluteSort(std::vector<int>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++)
		{
			comparison_counter++;
			if (abs(arr[tmpid]) >  abs(arr[j]))
			{
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i)
		{
			swap_counter++;
			std::swap(arr[i], arr[tmpid]);
		}
	}
}

void SelectionSort::Sort(std::vector<int>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++)
		{
			comparison_counter++;
			if ((arr[tmpid]) > arr[j])
			{
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i)
		{
			swap_counter++;
			std::swap(arr[i], arr[tmpid]);
		}
	}
}
