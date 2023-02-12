#include <PseudoGenerator.h>

PseudoGenerator::PseudoGenerator(const std::vector<int>& vec)
{
    _vec = vec;
    _len = vec.size();
}

int PseudoGenerator::Next()
{
    int val = _vec[_idxTop];
    _idxTop = (_idxTop + 1) % _len;

    return val;
}

void PseudoGenerator::Reset()
{
    _idxTop = 0;
}