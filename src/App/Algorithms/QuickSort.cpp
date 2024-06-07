#include "QuickSort.h"

QuickSort::QuickSort()
{
    this->m_name = "Quick Sort";
}

QuickSort &QuickSort::GetInstance()
{
    static QuickSort instance;
    return instance;
}

QuickSort::~QuickSort()
{
}

void QuickSort::Sort(std::vector<Bar> &bars)
{
    this->QuickSortHelper(bars, 0, bars.size() - 1);
}

void QuickSort::QuickSortHelper(std::vector<Bar> &bars, int low, int high)
{
    if (low < high)
    {
        int pi = this->Partition(bars, low, high);

        this->QuickSortHelper(bars, low, pi - 1);
        this->QuickSortHelper(bars, pi + 1, high);
    }
}

int QuickSort::Partition(std::vector<Bar> &bars, int low, int high)
{
    float pivot = bars[high].GetValue();
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (this->CompareGreater(pivot, bars[j]))
        {
            i++;
            this->Swap(bars[i], bars[j]);
        }
    }

    this->Swap(bars[i + 1], bars[high]);
    return i + 1;
}