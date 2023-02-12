#pragma once

#include "arduino.h"

class TimerNonBlock
{
private:
    int timeRemaining;
    int timestampPrev = -1;

public:
    void Start(int _timeRemaining);
    void Process();
    bool HasEnded();
    int GetRemainingTime();
};