
#include "ISort.h"
#include "Names.h"

int ISort::GetComprasionCounter()
{
	return comparison_counter;
}

int ISort::GetSwapCountrt()
{
	return swap_counter;
}

void ISort::PrintCounters()
{
	std::cout << "���������" << "\t\t" << "���������" << std::endl;
	std::cout << "\t" << comparison_counter << "\t\t" << swap_counter << std::endl;
}


