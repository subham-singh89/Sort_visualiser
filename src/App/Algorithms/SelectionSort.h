#pragma once

#include "Algorithm.h"

class SelectionSort : public Algorithm
{
    SelectionSort();

public:
    static SelectionSort &GetInstance();
    ~SelectionSort() override;
    void Sort(std::vector<Bar> &bars) override;
};
