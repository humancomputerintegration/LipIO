#include "Stimulator.h"

Stimulator::Stimulator(int numChannels)
{
    _numChannels = numChannels;
    _isPinHighs.reserve(numChannels);
    for(int i=0; i<numChannels; i++)
    {
        pinMode(PIN_STIMULATORS[i], OUTPUT);
        UpdateChannel(i, false);
    }
}

void Stimulator::UpdateChannel(int idx, bool isHigh)
{
    digitalWrite(PIN_STIMULATORS[idx], isHigh);
    _isPinHighs[idx] = isHigh;
}

void Stimulator::TurnOffAllChannels()
{
    for(int i=0; i<_numChannels; i++)
    {   
        UpdateChannel(i, false);
    }
}

void Stimulator::TurnOnSingleChannel(int idxOn)
{
    for(int i=0; i<_numChannels; i++)
    {
        UpdateChannel(i, (i == idxOn));
    }
}

int Stimulator::GetState(int idx)
{
    return (bool)_isPinHighs[idx];
}