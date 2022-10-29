#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Names.h"

class ISort
{
protected:

	int comparison_counter = 0;
	int swap_counter = 0;

public:

	int GetComprasionCounter();

	int GetSwapCountrt();

	virtual void PrintCounters();

	virtual void Sort(std::vector<int>& arr, int size) = 0;

	virtual ~ISort() = default;

};

