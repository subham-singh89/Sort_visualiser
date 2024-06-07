#include "CombSort.h"

CombSort::CombSort()
{
    this->m_name = "Comb Sort";
}

CombSort &CombSort::GetInstance()
{
    static CombSort instance;
    return instance;
}

CombSort::~CombSort()
{
}

void CombSort::Sort(std::vector<Bar> &bars)
{
    this->m_bars = &bars;

    int gap = bars.size();
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = (gap * 10) / 13;
        swapped = false;

        for (int i = 0; i < bars.size() - gap; i++)
        {
            if (this->CompareGreater(bars[i], bars[i + gap]))
            {
                this->Swap(bars[i], bars[i + gap]);
                swapped = true;
            }
        }
    }
}