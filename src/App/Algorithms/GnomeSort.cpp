#include "GnomeSort.h"

GnomeSort::GnomeSort()
{
    this->m_name = "Gnome Sort";
}

GnomeSort &GnomeSort::GetInstance()
{
    static GnomeSort instance;
    return instance;
}

GnomeSort::~GnomeSort()
{
}

void GnomeSort::Sort(std::vector<Bar> &bars)
{
    this->m_bars = &bars;

    int index = 0;

    while (index < bars.size())
    {
        if (index == 0)
        {
            index++;
        }

        ;
        if (this->CompareGreaterEqual(bars[index], bars[index - 1]))
        {
            index++;
        }
        else
        {
            this->Swap(bars[index], bars[index - 1]);
            index--;
        }
    }
}