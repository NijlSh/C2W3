#pragma once
#include <iostream>
#include <vector>
#include "ISort.h"
#include "GetColum.h"


class SortedMatrix
{
private:
	int number_of_lines;
	int number_of_colums;

	std::vector<std::vector<int>> matrix_colums;
	std::vector<std::vector<int>> matrix_lines;
	std::vector<std::vector<int>> SortLines(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort);
	std::vector<std::vector<int>> SortClumns(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort);

public:
	SortedMatrix( std::vector<std::vector <int>> matrix_value,std::shared_ptr<ISort> sort)
	{
		number_of_lines = static_cast<int>(matrix_value.size());
		number_of_colums = static_cast<int>(matrix_value[0].size());
		matrix_colums = SortLines(matrix_value, sort);
		matrix_lines = SortClumns(matrix_value, sort);
	}

	int GetNumberOflines();
	int GetNumberOfColums();
	std::vector<std::vector<int>> GetMatrixColums();
	std::vector<std::vector<int>> GetMatrixLines();

	void Show();
};

