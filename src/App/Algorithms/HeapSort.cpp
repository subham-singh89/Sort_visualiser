#include "HeapSort.h"

HeapSort::HeapSort()
{
    this->m_name = "Heap Sort";
}

HeapSort &HeapSort::GetInstance()
{
    static HeapSort instance;
    return instance;
}

HeapSort::~HeapSort()
{
}

void HeapSort::Sort(std::vector<Bar> &bars)
{
    this->m_bars = &bars;

    for (int i = bars.size() / 2 - 1; i >= 0; i--)
    {
        this->Heapify(bars, bars.size(), i);
    }

    for (int i = bars.size() - 1; i >= 0; i--)
    {
        this->Swap(bars[0], bars[i]);
        this->Heapify(bars, i, 0);
    }
}

void HeapSort::Heapify(std::vector<Bar> &bars, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && this->CompareGreater(bars[left], bars[largest]))
    {
        largest = left;
    }

    if (right < size && this->CompareGreater(bars[right], bars[largest]))
    {
        largest = right;
    }

    if (largest != index)
    {
        this->Swap(bars[index], bars[largest]);
        this->Heapify(bars, size, largest);
    }
}