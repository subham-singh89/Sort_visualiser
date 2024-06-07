#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
    this->m_name = "Bubble Sort";
}

BubbleSort &BubbleSort::GetInstance()
{
    static BubbleSort instance;
    return instance;
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::Sort(std::vector<Bar> &bars)
{
    this->m_bars = &bars;

    for (int i = 0; i < bars.size() - 1; i++)
    {
        for (int j = 0; j < bars.size() - i - 1; j++)
        {
            if (this->CompareGreater(bars[j], bars[j + 1]))
            {
                this->Swap(bars[j], bars[j + 1]);
            }
        }
    }
}