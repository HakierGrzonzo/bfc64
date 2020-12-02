#pragma once
struct StackMember {
    StackMember* previous = nullptr;
    int memoryShift = 0;
    int firstLine = 1;
};