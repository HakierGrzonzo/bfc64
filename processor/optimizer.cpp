#include "symbols/symbol.h"
#include <vector>
#include <math.h>
#include <iostream>

std::vector<Symbol> optimize(std::vector<Symbol> program)
{
    int currentTally = 0;
    std::vector<Symbol> optimized = std::vector<Symbol>();
    for (int i = 0; i < program.size(); i++)
    {
        switch (program[i].type)
        {
            case SymbolType::inc:
                currentTally++;
                break;
            case SymbolType::dec:
                currentTally--;
                break;
            default:
                if (currentTally == 1)
                {
                    optimized.push_back(Symbol(SymbolType::inc, fromOptimizer));
                }
                else if (currentTally == -1)
                {
                    optimized.push_back(Symbol(SymbolType::dec, fromOptimizer));
                }
                else if (currentTally > 1)
                {
                    optimized.push_back(Symbol(SymbolType::add, fromOptimizer, std::min(currentTally, 255)));
                }
                else if (currentTally < -1)
                {
                    optimized.push_back(Symbol(SymbolType::subtract, fromOptimizer, std::min(std::abs(currentTally), 255)));
                }
                currentTally = 0;
                optimized.push_back(program[i]);
        }
    }
    if (currentTally == 1)
    {
        optimized.push_back(Symbol(SymbolType::inc, fromOptimizer));
    }
    else if (currentTally == -1)
    {
        optimized.push_back(Symbol(SymbolType::dec, fromOptimizer));
    }
    else if (currentTally > 1)
    {
        optimized.push_back(Symbol(SymbolType::add, fromOptimizer, std::min(currentTally, 255)));
    }
    else if (currentTally < -1)
    {
        optimized.push_back(Symbol(SymbolType::subtract, fromOptimizer, std::min(std::abs(currentTally), 255)));
    }
    std::cout << "Size of program reduced by " << (((program.size() - optimized.size()) * 100) / program.size()) << "%" << std::endl;
    return optimized;
}