#include "ShellSort.h"

ShellSort::ShellSort()
{
    this->m_name = "Shell Sort";
}

ShellSort &ShellSort::GetInstance()
{
    static ShellSort instance;
    return instance;
}

ShellSort::~ShellSort()
{
}

void ShellSort::Sort(std::vector<Bar> &bars)
{
    int n = bars.size();

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            float temp = bars[i].GetValue();

            int j;

            for (j = i; j >= gap && this->CompareGreater(bars[j - gap], temp); j -= gap)
            {
                bars[j].SetValue(bars[j - gap].GetValue());
            }

            bars[j].SetValue(temp);
        }
    }
}