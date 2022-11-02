#include <windows.h>

#include "ISort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "MatrixInput.h"
#include "InitialMatrixFileOutput.h"
#include "SaveData.h"


enum class Answer 
{
	Yes = 1,
	No
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int const sorts_count = 5;
	std::cout << "Контрольная работа №4, вариант 4, сделано студентом группы 415 Шарашидзе Н.Л." << std::endl
		<< "Необходимо упорядочить каждую нечетную строку по возрастанию абсолютных величин, каждый четный столбец по возрастанию." << std::endl
		<< "Для этого необходимо использовать методы: пузырьковой, отбора, вставки, Шелла и быстрой сортировки." << std::endl
		<< "Вывести на экран неупорядоченный(один раз) и упорядоченные(для каждого из методов) массивы данных." << std::endl
		<< "Составить сравнительную таблицу эффективности методов, в которой необходимо указать число сравнений и перестановок переменных в каждом методе сортировки." << std::endl;
		
	while (true)
	{
		std::vector <std::shared_ptr<ISort>> sorts_case;
		std::vector <std::shared_ptr<SortedMatrix>> sorts_matrix;
		std::vector <std::vector<int>> matrix;

		sorts_case.emplace_back(std::make_shared<BubbleSort>());
		sorts_case.emplace_back(std::make_shared<QuickSort>());
		sorts_case.emplace_back(std::make_shared<SelectionSort>());
		sorts_case.emplace_back(std::make_shared<ShellSort>());
		sorts_case.emplace_back(std::make_shared<InsertionSort>());
		
		InputMode mode = static_cast<InputMode> (MatrixInput(matrix));

		for (int i = 0; i < static_cast<int>(matrix.size()); i++)
		{
			for (int j = 0; j < static_cast<int>(matrix[0].size()); j++)
			{
				std::cout << matrix[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < sorts_count; i++)
		{
			sorts_matrix.emplace_back(std::make_shared<SortedMatrix>(matrix, sorts_case[i]));
			sorts_case[i]->PrintCounters();
			sorts_matrix[i]->Show();
		}
		
		if (mode == InputMode::console_by_hand || mode == InputMode::console_random)
		{
			std::cout << "Вы хотите сохранить исходные данные матрицы в файл?" << std::endl;
			std::cout << "1 - Да\n2 - Нет" << std::endl;
			Answer initial_choice = static_cast<Answer> (InputCheck::CheckMenu(2));
			if (initial_choice == Answer::Yes)
				InitialMatrixFileOutput(matrix);
		}
		std::cout << "Вы хотите сохранить таблицу сравнения сортировки в файл?" << std::endl;
		std::cout << "1 - Да\n2 - Нет" << std::endl;
		Answer data_choice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if(data_choice == Answer::Yes)
			SaveData(sorts_case, sorts_matrix);

		std::cout << "Продолжить?" << std::endl;
		std::cout << "1 - Да\n2 - Нет" << std::endl;
		Answer continue_choice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if (continue_choice == Answer::No) return 0;		
		system("cls");
	}
	
}