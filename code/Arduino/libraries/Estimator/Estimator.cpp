#include "Estimator.h"

namespace Estimator
{
int Centroid(const std::vector<int>& data)
{
    int index = -1;

    bool isAboveZero = IsAnyAboveThresh(data, 0);

    if(isAboveZero)
    {
        int sumData = 0;
        int sumWeighted = 0;

        for (int i=0; i<data.size(); i++)
        {
            auto v = data[i];
            sumData += v;
            sumWeighted += i*v;
        }

        index = (int) round((float)sumWeighted/sumData);
    }

    return index;
}

int CentroidWithThresh(const std::vector<int>& data, const int thresh)
{
    int index = -1;

    bool isAboveThresh = IsAnyAboveThresh(data, thresh);
    if(isAboveThresh)
    {
        index = Centroid(data);
    }

    return index;
}

bool IsAnyAboveThresh(const std::vector<int>& data, const int thresh)
{
    bool isAnyAboveThresh = false;
    for (int i=0; i<data.size(); i++)
    {
        if(data[i] > thresh)
        {
            isAnyAboveThresh = true;
            break;
        }
    }

    return isAnyAboveThresh;
}

bool IsAllAboveThresh(const std::vector<int>& data, const int thresh)
{
    bool isAllAboveThresh = true;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i] <= thresh)
        {
            isAllAboveThresh = false;
            break;
        }
    }

    return isAllAboveThresh;
}
}