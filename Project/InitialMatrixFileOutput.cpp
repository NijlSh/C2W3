#include "InitialMatrixFileOutput.h"

void InitialMatrixFileOutput(std::vector<std::vector<int>> matrix)
{
	const int this_file = 1;
	std::string name;
	std::ofstream  file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	while (true)
	{
		try
		{
			name = GetFileName(output);
			file.open(name);
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка доступа." << std::endl;
			continue;
		}
		break;
	}

	int number_of_lines = static_cast<int> (matrix.size());
	int number_of_colums = static_cast<int>(matrix[0].size());


	file << number_of_lines << std::endl;
	file << number_of_colums << std::endl;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < number_of_colums; j++)
		{
			file << matrix[i][j] << std::endl;
		}
	}
	file.close();
}

