#pragma once

#include "Algorithm.h"

class CocktailSort : public Algorithm
{
    CocktailSort();

public:
    static CocktailSort &GetInstance();
    ~CocktailSort() override;
    void Sort(std::vector<Bar> &bars) override;
};