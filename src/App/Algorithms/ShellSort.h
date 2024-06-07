#pragma once

#include "Algorithm.h"

class ShellSort : public Algorithm
{
    ShellSort();

public:
    static ShellSort &GetInstance();
    ~ShellSort() override;
    void Sort(std::vector<Bar> &bars) override;
};