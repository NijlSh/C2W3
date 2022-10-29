#include "SaveData.h"

void SaveData(std::vector<std::shared_ptr<ISort>>& sorts_case, std::vector < std::shared_ptr<SortedMatrix>> sorts_matrix)
{
	const int this_file = 1;
	std::string name;
	std::ofstream file;
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
			std::cout << "������ �������." << std::endl;
			continue;
		}
		break;

	}
	std::vector<std::vector<int>> matrix_colums = sorts_matrix[0]->GetMatrixColums();
	std::vector<std::vector<int>> matrix_lines = sorts_matrix[0]->GetMatrixLines();

	file<< std::string(15,' ') << "���������" << "\t" << "���������" << std::endl;
	for (int i = 0; i < sorts_case.size(); i++)
	{
		std::string temp_name = typeid(*sorts_case[i]).name();
		temp_name.erase(0, 6);
		file << temp_name << std::string(15 - temp_name.size(),' ') << sorts_case[i]->GetComprasionCounter() << "\t\t\t" << sorts_case[i]->GetSwapCountrt() << std::endl;;
	}
	file << "\n��������������� ������ �������." << std::endl;
	for (int i = 0; i < sorts_matrix[0]->GetNumberOflines(); i++)
	{
		for (int j = 0; j < sorts_matrix[0]->GEtNumberOfColums(); j++)
		{
			file << matrix_colums[i][j] << "\t";
		}
		file << std::endl;
	}

	file << "��������������� �������� ������." << std::endl;
	for (int i = 0; i < sorts_matrix[0]->GetNumberOflines(); i++)
	{
		for (int j = 0; j < sorts_matrix[0]->GEtNumberOfColums(); j++)
		{
			file << matrix_colums[i][j] << "\t";
		}
		file << std::endl;
	}
		
	file.close();
}
