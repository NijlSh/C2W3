#pragma once

#include "ISort.h"


class QuickSort : public ISort
{
public:

	void PrintCounters() override;

	void Sort(std::vector<int>& arr, int size) override;

	void AbsoluteSort(std::vector<int>& arr, int size) override;

	void Quicksort(std::vector<int>& arr, int start, int end);

	void AbsoluteQuicksort(std::vector<int>& arr, int start, int end);

	int Partition(std::vector<int>& arr, int start, int end);

	int AbsolutePartition(std::vector<int>& arr, int start, int end);

};

