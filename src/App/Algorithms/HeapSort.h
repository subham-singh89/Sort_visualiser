#pragma once

#include "Algorithm.h"

class HeapSort : public Algorithm
{
    HeapSort();

public:
    static HeapSort &GetInstance();
    ~HeapSort() override;
    void Sort(std::vector<Bar> &bars) override;

private:
    void Heapify(std::vector<Bar> &bars, int size, int index);
};
