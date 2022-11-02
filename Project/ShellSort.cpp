#include "ShellSort.h"

void ShellSort::PrintCounters()
{
    std::cout << "Сортировка Шелла." << std::endl;
    ISort::PrintCounters();
}

void ShellSort::AbsoluteSort(std::vector<int>& arr, int size)
{
	for (int gap = size/2; gap > 0; gap/=2)
		for (int i = gap; i < size; i++)
		{
            int temp = arr[i];
            int j;
            comparison_counter++;
            for (j = i; j >= gap && abs(arr[j - gap]) > abs(temp); j -= gap)
            {
                swap_counter++;
                arr[j] = arr[j - gap];
                if (j == gap)
                    comparison_counter--;
            }

		arr[j] = temp;
		} 
}

void ShellSort::Sort(std::vector<int>& arr, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int j;
			comparison_counter++;
			for (j = i; j >= gap && (arr[j - gap]) > temp; j -= gap)
			{
				swap_counter++;
				arr[j] = arr[j - gap];
				if (j == gap)
					comparison_counter--;
			}

			arr[j] = temp;
		}
}