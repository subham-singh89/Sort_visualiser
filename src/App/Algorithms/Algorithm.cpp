#include "Algorithm.h"

void Algorithm::Swap(Bar &bar1, Bar &bar2)
{
    float temp = bar1.GetValue();
    bar1.SetValue(bar2.GetValue());
    bar2.SetValue(temp);
    this->m_numberOfSwaps++;
}

bool Algorithm::CompareGreater(Bar &bar1, Bar &bar2)
{
    this->m_numberOfComparisons++;
    return bar1.GetValue() > bar2.GetValue();
}

bool Algorithm::CompareGreater(Bar &bar1, float bar2)
{
    this->m_numberOfComparisons++;
    return bar1.GetValue() > bar2;
}

bool Algorithm::CompareGreater(float bar1, Bar &bar2)
{
    this->m_numberOfComparisons++;
    return bar1 > bar2.GetValue();
}

bool Algorithm::CompareGreaterEqual(Bar &bar1, Bar &bar2)
{
    this->m_numberOfComparisons++;
    return bar1.GetValue() >= bar2.GetValue();
}

void Algorithm::Reset()
{
    this->m_numberOfSwaps = 0;
    this->m_numberOfComparisons = 0;
}