#pragma once

#include <Arduino.h>
#include <ArduinoSTL.h>
#include <vector>

#include <CommonParams.h>

class TouchSequence
{
private:
    std::vector<int> _buf;
    int _numChannels;
    int _idxTop = 0;

public:
    TouchSequence(int numChannels);
    void Push(int idxTouch);
    void Reset();
    bool IsMatching(const std::vector<int>& series);
    String GetSequence();
};