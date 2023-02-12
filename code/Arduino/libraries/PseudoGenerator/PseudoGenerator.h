#pragma once

#include <ArduinoSTL.h>
#include <vector>

class PseudoGenerator
{
private:
    std::vector<int> _vec;
    int _idxTop = 0;
    int _len;

public:
    PseudoGenerator(const std::vector<int>& vec);
    int Next();
    void Reset();
};