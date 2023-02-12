#include <TouchSequence.h>

TouchSequence::TouchSequence(int numChannels)
{
    _numChannels = numChannels;
    for(int i=0; i<numChannels; i++)
    {
        _buf.push_back(-1);
    }
}

void TouchSequence::Push(int idxTouch)
{
    if((idxTouch == -1) || (idxTouch == _buf[(_idxTop + _numChannels - 1) % _numChannels])) return;

    _buf[_idxTop] = idxTouch;
    _idxTop = (_idxTop + 1) % _numChannels;
}

void TouchSequence::Reset()
{
    for(int i=0; i<_numChannels; i++)
    {
        _buf[i] = -1;
    }
}

bool TouchSequence::IsMatching(const std::vector<int>& series)
{
    if(series.size() != _numChannels) return false;

    bool isMatching = true;
    for(int i=0; i<_numChannels; i++)
    {
        if(series[i] != _buf[(_idxTop + i) % _numChannels])
        {
            isMatching = false;
            break;
        }
    }

    return isMatching;
}

String TouchSequence::GetSequence()
{
    String s = "";
    for(int i=0; i<_numChannels; i++)
    {
        s += String(_buf[(_idxTop + i) % _numChannels]);
        if(i<_numChannels-1) s += ",";
    }

    return s;
}