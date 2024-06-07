#pragma once

#include "Algorithm.h"

class QuickSort : public Algorithm
{
    QuickSort();

public:
    static QuickSort &GetInstance();
    ~QuickSort() override;
    void Sort(std::vector<Bar> &bars) override;

private:
    void QuickSortHelper(std::vector<Bar> &bars, int left, int right);
    int Partition(std::vector<Bar> &bars, int left, int right);
};