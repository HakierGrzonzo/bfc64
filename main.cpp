#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "processor/processor.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "bfc64 must be launched with 1 argument being a source file!" << std::endl;
        return 1;
    }
    std::ifstream source;
    source.open(argv[1]);
    if (!source.is_open())
    {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }
    std::cerr << "Starting bfc64 v.0" << std::endl;
    try
    {
        std::string output = compiler(parseSourceFile(source));
        std::cout << output;
    }
    catch (std::runtime_error e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}