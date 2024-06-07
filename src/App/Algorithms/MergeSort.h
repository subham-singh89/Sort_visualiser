#pragma once

#include <vector>

#include "Algorithm.h"

class MergeSort : public Algorithm
{
    MergeSort();

public:
    static MergeSort &GetInstance();
    ~MergeSort() override;
    void Sort(std::vector<Bar> &bars) override;

private:
    void MergeSortHelper(int left, int right);
    void Merge(int left, int middle, int right);
};