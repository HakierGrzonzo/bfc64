#include <vector>
#include <fstream>
#include <iostream>
#include "symbols/symbol.h"
#include "stack.h"
#include <string>

std::vector<Symbol> parseSourceFile(std::ifstream& sourceFile)
{
    int lineNumber = 1;
    auto parsed = std::vector<Symbol>();
    StackMember* stackptr = new StackMember;
    StackMember* tmp = nullptr;
    while (sourceFile.good())
    {
        char x;
        sourceFile.get(x);
        switch (x)
        {
            case '\n':
                lineNumber++; // advance lineNumber so we can give syntax error location 
                break;
            case '>':
                parsed.push_back(Symbol(SymbolType::right, lineNumber));
                stackptr -> memoryShift++;
                break;
            case '<':
                parsed.push_back(Symbol(SymbolType::left, lineNumber));
                stackptr -> memoryShift--;
                break;
            case '+':
                parsed.push_back(Symbol(SymbolType::inc, lineNumber));
                break;
            case '-':
                parsed.push_back(Symbol(SymbolType::dec, lineNumber));
                break;
            case '[':
                parsed.push_back(Symbol(SymbolType::loopBegin, lineNumber));
                stackptr = new StackMember {stackptr, 0, lineNumber};
                break;
            case ']':
                parsed.push_back(Symbol(SymbolType::loopEnd, lineNumber));
                if (stackptr -> memoryShift != 0)
                {
                    std::cerr << "WARN: Possible runaway loop in lines " << stackptr -> firstLine << "-" << lineNumber << std::endl;
                }
                if (stackptr -> previous == nullptr)
                {
                    throw std::runtime_error(std::string("SyntaxError: EOF expected, ']' found in line ") + std::to_string(lineNumber));
                }
                tmp = stackptr;
                stackptr = stackptr -> previous;
                delete tmp;
                break;
            case '.':
                parsed.push_back(Symbol(SymbolType::out, lineNumber));
                break;
            case ',':
                parsed.push_back(Symbol(SymbolType::in, lineNumber));
                break;
            default:
                break; // Everything else is a comment
        }
    }
    if (stackptr -> previous != nullptr)
    {
        throw std::runtime_error("SyntaxError: ']' expected, EOF found");
    }
    sourceFile.close();
    return parsed;
}
