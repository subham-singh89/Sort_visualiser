#include "CocktailSort.h"

CocktailSort::CocktailSort()
{
    this->m_name = "Cocktail Sort";
}

CocktailSort &CocktailSort::GetInstance()
{
    static CocktailSort instance;
    return instance;
}

CocktailSort::~CocktailSort()
{
}

void CocktailSort::Sort(std::vector<Bar> &bars)
{
    int start = 0;
    int end = bars.size() - 1;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; i++)
        {
            if (this->CompareGreater(bars[i], bars[i + 1]))
            {
                this->Swap(bars[i], bars[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--)
        {
            if (this->CompareGreater(bars[i], bars[i + 1]))
            {
                this->Swap(bars[i], bars[i + 1]);
                swapped = true;
            }
        }

        start++;
    }
}