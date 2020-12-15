#pragma once
#include <string>

namespace arch {
    std::string dec(std::string label);
    std::string inc(std::string label);
    std::string left(std::string label);
    std::string right(std::string label);
    std::string in(std::string label);
    std::string loopBegin(std::string labelBegin, std::string labelEnd, std::string label);
    std::string loopEnd(std::string labelBegin, std::string labelEnd);
    std::string begin();
    std::string out();
    std::string end();
}