#pragma once

#include "symbols/symbol.h"
#include <vector>
#include <fstream>

std::vector<Symbol> parseSourceFile(std::ifstream& sourceFile);
