#include "QuickSort.h"

void QuickSort::PrintCounters()
{
	std::cout << "Быстрая сортировка." << std::endl;
	ISort::PrintCounters();
}

void QuickSort::Sort(std::vector<int>& arr, int size)
{
	Quicksort(arr, 0, size-1);
}

void QuickSort::Quicksort(std::vector<int>& arr, int start, int end)
{
	if (start < end) {
		int p = Partition(arr, start, end);
		Quicksort(arr, start, p - 1);
		Quicksort(arr, p + 1, end);
	}
}

int QuickSort::Partition(std::vector<int>& arr, int start, int end)
{
	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		comparison_counter++;
		if (abs(arr[i])  < abs(arr[pivot])) {
			swap_counter++;
			std::swap(arr[i], arr[j]);
			++j;
		}
	}
	std::swap(arr[j], arr[pivot]);
	if(swap_counter > 0)
		swap_counter++;
	return j;

}

