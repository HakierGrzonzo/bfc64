# pragma once
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

#define fromOptimizer -1

class Symbol {
    public:
        SymbolType type;
        int charNumber;
        int optimizedValue;
        Symbol(SymbolType _type, int _charNumber, int _optimizedValue = -1);
};