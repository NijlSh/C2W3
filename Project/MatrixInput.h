#pragma once
#include "SortedMatrix.h"
#include "InputCheck.h"
#include "GetFileName.h"


int MatrixInput(std::vector<std::vector<int>>& matrix);

std::vector<std::vector<int>> ConsoleInput();
std::vector<std::vector<int>> FileInput();
std::vector<std::vector<int>> RandomInput();