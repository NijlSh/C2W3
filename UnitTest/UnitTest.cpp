#include "pch.h"

#include "CppUnitTest.h"

#include "../Project/ISort.h"
#include "../Project/ISort.cpp"
#include "../Project/BubbleSort.h"
#include "../Project/BubbleSort.cpp"
#include "../Project/InsertionSort.h"
#include "../Project/InsertionSort.cpp"
#include "../Project/SelectionSort.h"
#include "../Project/SelectionSort.cpp"
#include "../Project/ShellSort.h"
#include "../Project/ShellSort.cpp"
#include "../Project/QuickSort.h"
#include "../Project/QuickSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

	private:
		BubbleSort bubleSort;
		InsertionSort insertionSort;
		SelectionSort selectionSort;
		ShellSort shellSort;
		QuickSort quickSort;
		std::vector <int> result = { 1,2,3,4,5 };
		std::vector <int> start = { 5,4,1,2,3 };
	public:

		TEST_METHOD(BubleTest)
		{
			std::vector <int> temp = start;
			bubleSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(InsertionTest)
		{
			std::vector <int> temp = start;
			insertionSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(SelectionTest)
		{
			std::vector <int> temp = start;
			selectionSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(ShellTest)
		{
			std::vector <int> temp = start;
			shellSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(QuickTest)
		{
			std::vector <int> temp = start;
			quickSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}
	};
};
