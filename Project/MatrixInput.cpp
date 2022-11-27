#include "MatrixInput.h"
#include <time.h>


int  MatrixInput(std::vector<std::vector<int>>& matrix)
{

	std::cout << "1 - Заполнениить матрицу вручную;" << std::endl
		<< "2 - Заполнить матрицу рандомными значениями;" << std::endl
		<< "3 - Заполнить матрицу из файла." << std::endl;
	InputMode mode = static_cast<InputMode>(InputCheck::CheckMenu(3));
	switch (mode)
	{
	case InputMode::console_by_hand:
		matrix = ConsoleInput();
		break;

	case InputMode::console_random:
		matrix = RandomInput();
		break;

	case InputMode::io_file:
		matrix = FileInput();
		break;

		
	}
	return static_cast<int>(mode);
}

std::vector<std::vector<int>> ConsoleInput()
{
	
		std::cout << "Введите количество строк." << std::endl;;
		int lines = InputCheck::CheckIntValuePlus();
		std::cout << "Введите количество столбцов." << std::endl;;
		int colums = InputCheck::CheckIntValuePlus();

		std::vector<std::vector<int>> matrix;

		for (int i = 0; i < lines; i++)
		{
			matrix.push_back(std::vector<int>{});
			for (int j = 0; j < colums; j++)
			{
				std::cout << "Ввод [" << i + 1 << "] [" << j + 1 << "] ." << std::endl;
				matrix[i].push_back(InputCheck::CheckIntValue());
			}
		}
		return matrix;
}

std::vector<std::vector<int>> FileInput()
{
	std::string name = "";
	std::ifstream file;
	std::vector<std::vector<int>> matrix;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		try
		{
			name = GetFileName(input);
			file.open(name);
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка доступа." << std::endl;
			continue;
		}

		try
		{
			int lines = (InputCheck::CheckLineUnsInt(file));
			int colums = (InputCheck::CheckLineUnsInt(file));
			if (lines <= 0 || colums <= 0) 



			for (int i = 0; i < lines; i++)
			{
				matrix.push_back(std::vector<int>{});
				for (int j = 0; j < colums; j++)
				{
					matrix[i].push_back( InputCheck::CheckLineInt(file));
				}
			}
		}
		catch (std::exception&)
		{
			file.close();
			continue;
		}
		std::cin.clear();
		std::cin.ignore();
		file.close();
		return matrix;
	}
}

std::vector<std::vector<int>>  RandomInput() 
{
	srand(static_cast<unsigned>(time(nullptr)));
	std::cout << "Введите строки." << std::endl;;
	int lines = InputCheck::CheckIntValuePlus();
	std::cout << "Введите столбцы." << std::endl;;
	int colums = InputCheck::CheckIntValuePlus();

	std::vector<std::vector<int>> matrix;

	for (int i = 0; i < lines; i++)
	{
		matrix.push_back(std::vector<int>{});
		for (int j = 0; j < colums; j++)
		{
			matrix[i].push_back(std::rand() % 101 - 50);
		}
	}
	return matrix;
}

