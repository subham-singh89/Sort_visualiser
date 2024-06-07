#pragma once

#include "Algorithm.h"

class CombSort : public Algorithm
{
    CombSort();

public:
    static CombSort &GetInstance();
    ~CombSort() override;
    void Sort(std::vector<Bar> &bars) override;
};