#pragma once

#include "Algorithm.h"

class GnomeSort : public Algorithm
{
    GnomeSort();

public:
    static GnomeSort &GetInstance();
    ~GnomeSort() override;
    void Sort(std::vector<Bar> &bars) override;
};
