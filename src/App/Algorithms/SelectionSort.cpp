#include "SelectionSort.h"

#include <algorithm>

SelectionSort::SelectionSort()
{
    this->m_name = "Selection Sort";
}

SelectionSort::~SelectionSort()
{
}

SelectionSort &SelectionSort::GetInstance()
{
    static SelectionSort instance;
    return instance;
}

void SelectionSort::Sort(std::vector<Bar> &bars)
{
    for (int i = 0; i < bars.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < bars.size(); j++)
        {
            if (this->CompareGreater(bars[minIndex], bars[j]))
            {
                minIndex = j;
            }
        }

        this->Swap(bars[i], bars[minIndex]);
    }
}