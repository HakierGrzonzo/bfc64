#include <iostream>
#include <vector>
#include "symbols/symbol.h"
#include <string>
#include "arch/template.hpp"

struct loopStack {
    loopStack* prev;
    std::string labelBegin;
    std::string labelEnd;
};

std::string getLabel(unsigned int i)
{
    return "label" + std::to_string(i);
}

std::string compiler(std::vector<Symbol> program)
{
    std::string result = arch::begin();
    unsigned int labelCounter = 1;
    loopStack* stack = nullptr;
    for (int y = 0; y < program.size(); y++)
    {
        loopStack* tmp = nullptr;
        switch(program[y].type)
        {
            case SymbolType::inc:
                result += arch::inc(getLabel(labelCounter++));
                break;
            case SymbolType::dec:
                result += arch::dec(getLabel(labelCounter++));
                break;
            case SymbolType::left:
                result += arch::left(getLabel(labelCounter++));
                break;
            case SymbolType::right:
                result += arch::right(getLabel(labelCounter++));
                break;
            case SymbolType::in:
                result += arch::in(getLabel(labelCounter++));
                break;
            case SymbolType::loopBegin:
                stack = new loopStack {stack, getLabel(labelCounter), getLabel(labelCounter + 1)};
                labelCounter += 2;
                result += arch::loopBegin(stack->labelBegin, stack->labelEnd, getLabel(labelCounter++));
                break;
            case SymbolType::loopEnd:
                result += arch::loopEnd(stack->labelBegin, stack->labelEnd);
                tmp = stack;
                stack = stack->prev;
                delete tmp;
                break;
            case SymbolType::out:
                result += arch::out();
                break;
            case SymbolType::add:
                result += arch::add(std::to_string(program[y].optimizedValue), getLabel(labelCounter++));
                break;
            case SymbolType::subtract:
                result += arch::subtract(std::to_string(program[y].optimizedValue), getLabel(labelCounter), getLabel(labelCounter + 1));
                labelCounter += 2;
                break;
            default:
                throw std::runtime_error("Not implemented");
        }
    }
    result += arch::end();
    return result;
}