#pragma once

#include <Arduino.h>
#include <Adafruit_MPR121.h>
#include <ArduinoSTL.h>
#include <vector>

#include <Estimator.h>

class Sensor
{
private:
    Adafruit_MPR121 _cap = Adafruit_MPR121();
    int _numChannels;
    int _thresh;
    std::vector<int> _droppings;

public:
    Sensor(int numChannels, int thresh);
    void Initialize();
    int CalculateIdxTouch();
    int GetDropping(int idx);
    String GetAllDroppings();
};