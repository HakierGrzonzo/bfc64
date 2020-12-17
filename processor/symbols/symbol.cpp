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
    out,
    null
}; 

#define fromOptimizer -1

class Symbol {
    public:
        SymbolType type;
        int charNumber;
        int optimizedValue;
        Symbol(SymbolType _type, int _charNumber, int _optimizedValue = -1);
};

Symbol::Symbol (SymbolType _type, int _charNumber, int _optimizedValue)
{
    if (
           (type == SymbolType::add ||
            type == SymbolType::subtract ||
            type == SymbolType::jmpLeft ||
            type == SymbolType::jmpRight ) && optimizedValue == -1
        )
    {
        // Trust nobody
        throw std::invalid_argument("Optimized symbol in Symbol is not permitted!"); 
    }
    else if (_optimizedValue != -1 && _charNumber != fromOptimizer)
    {
        throw std::invalid_argument("if optimizedValue than must be fromOptimizer");
    }
    type = _type;
    charNumber = _charNumber;
    optimizedValue = _optimizedValue;
}