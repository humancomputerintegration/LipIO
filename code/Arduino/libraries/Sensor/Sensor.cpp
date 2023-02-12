#include "Sensor.h"

Sensor::Sensor(int numChannels, int thresh)
{
    _numChannels = numChannels;
    _thresh = thresh;
    for(int i=0; i<numChannels; i++)
    {
        _droppings.push_back(0);
    }
}

void Sensor::Initialize()
{
    while (!Serial)
    { // needed to keep leonardo/micro from starting too fast!
        delay(10);
    }

    // Serial.println("SystAdafruit MPR121 Capacitive Touch sensor visualize"); 

    if (!_cap.begin(0x5A)) 
    {
        // Serial.println("SystMPR121 not found, check wiring?");
        while (1);
    }
    // Serial.println("SystMPR121 found!");

    _cap.setThresholds(8,6);
}

int Sensor::CalculateIdxTouch()
{
    for (uint8_t i = 0; i < _numChannels; i++)
    {
        int idxPin = PIN_SENSORS[i];
        int v = int(_cap.baselineData(idxPin)-_cap.filteredData(idxPin));
        if(v < 0) v = 0;
        _droppings[i] = v;
    }

    // 13 (All, massive touch)
    bool isAllAboveThresh = Estimator::IsAllAboveThresh(_droppings, _thresh);
    if(isAllAboveThresh)
    {
        return IDX_PA;
    }

    // // -1 (none), 0 - 12
    int idxTouch = Estimator::CentroidWithThresh(_droppings, _thresh);

    return idxTouch;
}

int Sensor::GetDropping(int idx)
{
    return _droppings[idx];
}

String Sensor::GetAllDroppings()
{
    String s = "";
    for(int i=0; i<_numChannels; i++)
    {
        s += String(_droppings[i]);
        if(i<_numChannels-1) s += ",";
    }

    return s;
}