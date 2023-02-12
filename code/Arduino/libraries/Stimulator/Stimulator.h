#pragma once

#include <Arduino.h>
#include <ArduinoSTL.h>
#include <vector>

#include <CommonParams.h>

class Stimulator
{
private:
    int _numChannels;
    std::vector<bool> _isPinHighs;

    void UpdateChannel(int idx, bool isHigh);

public:
    Stimulator(int numChannels);
    
    void TurnOffAllChannels();
    void TurnOnSingleChannel(int idxOn);

    int GetState(int idx);
};