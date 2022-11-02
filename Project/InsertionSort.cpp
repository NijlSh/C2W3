#include "InsertionSort.h"

void InsertionSort::PrintCounters()
{
	std::cout << "Сортировка вставками." << std::endl;
	ISort::PrintCounters();
}

void InsertionSort::AbsoluteSort(std::vector<int>& arr, int size)
{
    for (int k = 1; k < size; k++)
    {
       
        int temp = arr[k];
        int j = k - 1;
        comparison_counter++;
        while (j >= 0 && abs(temp) < abs(arr[j]))
        {
            comparison_counter++;
            swap_counter++;
            arr[j + 1] = arr[j];
            j--;
            if(j==0)
                comparison_counter--;

        }
       arr[j + 1] = temp;
    }
}

void InsertionSort::Sort(std::vector<int>& arr, int size)
{
	for (int k = 1; k < size; k++)
	{

		int temp = arr[k];
		int j = k - 1;
		comparison_counter++;
		while (j >= 0 && temp < arr[j])
		{
			comparison_counter++;
			swap_counter++;
			arr[j + 1] = arr[j];
			j--;
			if (j == 0)
				comparison_counter--;

		}
		arr[j + 1] = temp;
	}
}
