#pragma once
#include <vector>
#include <memory>
#include <fstream>

#include "InputCheck.h"
#include "SortedMatrix.h"
#include "GetFileName.h"
#include "ISort.h"

void SaveData(std::vector<std::shared_ptr<ISort>>& sorts_case, std::vector < std::shared_ptr<SortedMatrix>> sorts_matrix);


