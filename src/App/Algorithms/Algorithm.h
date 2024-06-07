#pragma once

#include <vector>
#include <string>

#include "../Bar/Bar.h"

class Algorithm
{
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;
    virtual void Sort(std::vector<Bar> &bars) = 0;
    int GetNumberOfSwaps() const { return this->m_numberOfSwaps; }
    int GetNumberOfComparisons() const { return this->m_numberOfComparisons; }
    std::string GetName() const { return this->m_name; }

    void SetNumberOfComparisons(int &numberOfComparisons) { numberOfComparisons = this->m_numberOfComparisons; }
    void SetNumberOfSwaps(int &numberOfSwaps) { numberOfSwaps = this->m_numberOfSwaps; }

protected:
    void Reset();
    bool CompareGreater(Bar &first, Bar &second);
    bool CompareGreater(Bar &first, float second);
    bool CompareGreater(float first, Bar &second);
    bool CompareGreaterEqual(Bar &first, Bar &second);
    void Swap(Bar &first, Bar &second);

protected:
    std::vector<Bar> *m_bars = nullptr;
    std::string m_name = "";
    int m_numberOfSwaps = 0;
    int m_numberOfComparisons = 0;
};