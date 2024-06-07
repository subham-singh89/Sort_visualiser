#include "MainPanel.h"

#include <iostream>

MainPanel::MainPanel()
{
}

MainPanel::~MainPanel()
{
}

void MainPanel::Update()
{
    if (this->m_bars == nullptr)
        return;

    for (int i = 0; i < this->m_bars->size(); i++)
    {
        float width = this->m_size.x / this->m_bars->size();
        float height = this->m_size.y * 0.75f * i / this->m_bars->size();

        float x = this->m_position.x + width * i * 0.8f + this->m_size.x * 0.1f;
        float y = this->m_position.y + this->m_size.y * 0.9f;

        (*this->m_bars)[i].SetValue(x);
        (*this->m_bars)[i].SetPosition({x, y});
        (*this->m_bars)[i].SetSize({width, height});
    }
}

MainPanel &MainPanel::GetInstance()
{
    static MainPanel instance;
    return instance;
}

void MainPanel::Draw()
{
    DrawText("Status: ", this->m_position.x + 10.0f, this->m_position.y + 10.0f, 15, GREEN);
    float width = MeasureText("Status: ", 15);

    switch (this->m_state)
    {
    case State::Sorting:
        DrawText("Sorting...", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    case State::Shuffling:
        DrawText("Shuffling...", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    case State::Shuffled:
        DrawText("Shuffled", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    case State::Sorted:
        DrawText("Sorted", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    case State::Unsorted:
        DrawText("Unsorted", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    case State::Generated:
        DrawText("Generated", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    case State::Generating:
        DrawText("Generating...", this->m_position.x + 10.0f + width, this->m_position.y + 10.0f, 15, GREEN);
        break;
    default:
        break;
    }

    std::string nob = "Number of bars: " + std::to_string(this->m_numberOfBars);
    DrawText(nob.c_str(), this->m_position.x + 10.0f, this->m_position.y + 30.0f, 15, GREEN);
    std::string noc = "Number of comparisons: " + std::to_string(this->m_numberOfComparisons);
    DrawText(noc.c_str(), this->m_position.x + 10.0f, this->m_position.y + 50.0f, 15, GREEN);
    std::string nos = "Number of swaps: " + std::to_string(this->m_numberOfSwaps);
    DrawText(nos.c_str(), this->m_position.x + 10.0f, this->m_position.y + 70.0f, 15, GREEN);

    if (this->m_algorithmName != "")
    {
        std::string an = "Algorithm name: " + this->m_algorithmName;
        width = MeasureText(an.c_str(), 15);
        DrawText(an.c_str(), this->m_position.x + this->m_size.x - width - 10.0f, this->m_position.y + 10.0f, 15, GREEN);
    }

    std::string warning = "Warning: ";
    std::string tfb = warning + "Too few bars";
    std::string tmb = warning + "Too many bars";
    std::string ss = warning + "Still sorting";
    std::string nas = warning + "No algorithm selected";
    std::string ssg = warning + "Still shuffling";
    std::string asd = warning + "Already shuffled";
    std::string as = warning + "Already sorted";

    switch (this->m_warningStatus)
    {
    case WarningStatus::None:
        break;
    case WarningStatus::TooFewBars:
        width = MeasureText(tfb.c_str(), 20);
        DrawText(tfb.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    case WarningStatus::TooManyBars:
        width = MeasureText(tmb.c_str(), 20);
        DrawText(tmb.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    case WarningStatus::StillSorting:
        width = MeasureText(ss.c_str(), 20);
        DrawText(ss.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    case WarningStatus::NoAlgorithmSelected:
        width = MeasureText(nas.c_str(), 20);
        DrawText(nas.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    case WarningStatus::StillShuffling:
        width = MeasureText(ssg.c_str(), 20);
        DrawText(ssg.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    case WarningStatus::AlreadyShuffled:
        width = MeasureText(asd.c_str(), 20);
        DrawText(asd.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    case WarningStatus::AlreadySorted:
        width = MeasureText(as.c_str(), 20);
        DrawText(as.c_str(), this->m_position.x + this->m_size.x / 2.0f - width / 2.0f, this->m_position.y + 10.0f, 20, RED);
        break;
    default:
        break;
    }

    if (this->m_bars == nullptr)
        return;

    for (int i = 0; i < this->m_bars->size(); i++)
    {
        this->m_bars->at(i).Draw();
    }
}

void MainPanel::SetBars(std::vector<Bar> *bars)
{
    if (bars == nullptr)
        return;

    this->m_bars = bars;
}

void MainPanel::GenerateBars(std::vector<Bar> &bars)
{
    if (this->m_numberOfBars == 0)
        return;

    if (bars.size() != 0)
        bars.clear();

    for (int i = 0; i < this->m_numberOfBars; i++)
    {
        float value = (float)i / this->m_numberOfBars;

        float width = this->m_size.x / this->m_numberOfBars;
        float height = this->m_size.y * value * 0.75f;

        float x = this->m_position.x + width * i * 0.8f + this->m_size.x * 0.1f;
        float y = this->m_position.y + this->m_size.y * 0.9f;

        Bar bar;
        bar.SetValue(x);
        bar.SetColor(value);
        bar.SetPosition(Vector2{x, y});
        bar.SetSize(Vector2{width, height});
        bars.emplace_back(bar);
    }
}