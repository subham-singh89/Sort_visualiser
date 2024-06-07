#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
    this->m_name = "Insertion Sort";
}

InsertionSort &InsertionSort::GetInstance()
{
    static InsertionSort instance;
    return instance;
}

InsertionSort::~InsertionSort()
{
}

void InsertionSort::Sort(std::vector<Bar> &bars)
{
    for (int i = 1; i < bars.size(); i++)
    {
        float key = bars[i].GetValue();
        int j = i - 1;

        while (j >= 0 && this->CompareGreater(bars[j], key))
        {
            bars[j + 1].SetValue(bars[j].GetValue());
            j--;
        }

        bars[j + 1].SetValue(key);
    }
}
