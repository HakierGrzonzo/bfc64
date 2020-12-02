#include <stdexcept>
enum SymbolType {
    inc, // Add one to A
    dec, 
    add, // add more than one to A, used in optimizer
    subtract,
    left, // move head left by one space
    right,
    jmpLeft, // move head left by more than one space, used in optimizer
    jmpRight,
    loopBegin,
    loopEnd,
    in,
    out
}; 

#define fromOptymizer -1

class Symbol {
    public:
        SymbolType type;
        int charNumber;
        Symbol(SymbolType _type, int _charNumber);
};

class CmplxSymbol : Symbol {
    public:
        int optimizedValue;
        CmplxSymbol(SymbolType _type, int optimizedValue);
};

Symbol::Symbol (SymbolType _type, int _charNumber)
{
    if (
            type == SymbolType::add ||
            type == SymbolType::subtract ||
            type == SymbolType::jmpLeft ||
            type == SymbolType::jmpRight
        )
    {
        // Trust nobody
        throw std::invalid_argument("Optimized symbol in Symbol is not permitted!"); 
    }
    type = _type;
    charNumber = _charNumber;
}

CmplxSymbol::CmplxSymbol (SymbolType _type, int _optimizedValue)
{
    type = _type;
    charNumber = fromOptymizer;
    optimizedValue = _optimizedValue;
}