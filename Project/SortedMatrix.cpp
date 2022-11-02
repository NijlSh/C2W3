#include "SortedMatrix.h"

std::vector<std::vector<int>> SortedMatrix::SortLines(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort)
{
	std::vector<int> temp_column;
	for (int i = 1; i < number_of_colums; i += 2)
	{
		temp_column = GetColum(matrix, i, number_of_lines);
		sort -> Sort(temp_column, number_of_lines);
		SetColum(matrix, temp_column, i, number_of_lines);
	}
	return matrix;
}

std::vector<std::vector<int>> SortedMatrix::SortClumns(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort)
{
	for (int i = 0; i < number_of_lines; i += 2)
	{
		sort -> AbsoluteSort(matrix[i], number_of_colums);
	}
	return matrix;
}

int SortedMatrix::GetNumberOflines()
{
	return number_of_lines;
}

int SortedMatrix::GetNumberOfColums()
{
	return number_of_colums;
}

std::vector<std::vector<int>> SortedMatrix::GetMatrixColums()
{
	return matrix_colums;
}

std::vector<std::vector<int>> SortedMatrix::GetMatrixLines()
{
	return matrix_lines;
}

void SortedMatrix::Show()
{
	
	std::cout << "Отсортированные столбцы." << std::endl;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < number_of_colums; j++)
		{
			std::cout << matrix_colums[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n" << std::endl;
	std::cout << "Отсортированные строки." << std::endl;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < number_of_colums; j++)
		{
			std::cout << matrix_lines[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n" << std::endl;
}
