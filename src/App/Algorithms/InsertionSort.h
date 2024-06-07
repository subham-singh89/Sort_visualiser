#pragma once

#include "Algorithm.h"

class InsertionSort : public Algorithm
{
    InsertionSort();

public:
    static InsertionSort &GetInstance();
    ~InsertionSort() override;
    void Sort(std::vector<Bar> &bars) override;
};