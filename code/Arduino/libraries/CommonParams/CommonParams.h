#pragma once

#include <ArduinoSTL.h>
#include <vector>

const int NUM_CHANNELS = 5;
const int THRESH_SENSOR = 15;
const int BAUD_RATE = 115200;
const int IDX_PA = 13;

// Sensor
const int PIN_SENSORS[NUM_CHANNELS] = {9, 7, 5, 3, 1};

// Stimulator
const int PIN_STIMULATORS[NUM_CHANNELS] = {0, 1, 2, 3, 6};

// Touch Sequence
const std::vector<int> SEQ_ASCENDING = {0, 1, 2, 3, 4};
const std::vector<int> SEQ_DESCENDING = {4, 3, 2, 1, 0};