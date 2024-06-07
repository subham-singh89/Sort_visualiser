#include "MergeSort.h"

MergeSort::MergeSort()
{
    this->m_name = "Merge Sort";
}

MergeSort &MergeSort::GetInstance()
{
    static MergeSort instance;
    return instance;
}

MergeSort::~MergeSort()
{
}

void MergeSort::Sort(std::vector<Bar> &bars)
{
    this->m_bars = &bars;
    this->MergeSortHelper(0, bars.size() - 1);
}

void MergeSort::MergeSortHelper(int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        this->MergeSortHelper(left, middle);
        this->MergeSortHelper(middle + 1, right);

        this->Merge(left, middle, right);
    }
}

void MergeSort::Merge(int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    std::vector<Bar> leftArray(leftSize);
    std::vector<Bar> rightArray(rightSize);

    for (int i = 0; i < leftSize; i++)
    {

        leftArray[i] = this->m_bars->at(left + i);
    }

    for (int i = 0; i < rightSize; i++)
    {
        rightArray[i] = this->m_bars->at(middle + 1 + i);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (this->CompareGreaterEqual(rightArray[j], leftArray[i]))
        {
            this->m_bars->at(k).SetValue(leftArray[i].GetValue());
            i++;
            this->m_numberOfSwaps++;
        }
        else
        {
            this->m_bars->at(k).SetValue(rightArray[j].GetValue());
            this->m_numberOfSwaps++;

            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        this->m_bars->at(k).SetValue(leftArray[i].GetValue());
        this->m_numberOfSwaps++;

        i++;
        k++;
    }

    while (j < rightSize)
    {
        this->m_bars->at(k).SetValue(rightArray[j].GetValue());
        this->m_numberOfSwaps++;

        j++;
        k++;
    }
}