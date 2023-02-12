#pragma once

#include <math.h>
#include <ArduinoSTL.h>
#include <vector>

#include <CommonParams.h>

namespace Estimator
{
int Centroid(const std::vector<int>& data);
int CentroidWithThresh(const std::vector<int>& data, const int thresh);
bool IsAnyAboveThresh(const std::vector<int>& data, const int thresh);
bool IsAllAboveThresh(const std::vector<int>& data, const int thresh);
}