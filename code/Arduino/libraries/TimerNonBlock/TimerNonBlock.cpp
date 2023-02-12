#include <TimerNonBlock.h>

void TimerNonBlock::Start(int _timeRemaining)
{
    timeRemaining = _timeRemaining;
    timestampPrev = -1;
}

void TimerNonBlock::Process()
{
    int timestampCurr = millis();
    if (timestampPrev != -1)
    {
        timeRemaining -= (timestampCurr - timestampPrev);
    }
    timestampPrev = timestampCurr;
}

bool TimerNonBlock::HasEnded()
{
    return (timeRemaining <= 0);
}

int TimerNonBlock::GetRemainingTime()
{
    return timeRemaining;
}
