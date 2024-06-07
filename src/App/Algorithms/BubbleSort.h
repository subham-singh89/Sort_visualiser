#pragma once

#include "Algorithm.h"

class BubbleSort : public Algorithm
{
    BubbleSort();

public:
    static BubbleSort &GetInstance();
    ~BubbleSort() override;
    void Sort(std::vector<Bar> &bars) override;
};
