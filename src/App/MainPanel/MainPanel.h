#pragma once

#include <vector>
#include <raylib.h>
#include <string>

#include "../Bar/Bar.h"

#include "../Status.h"

class MainPanel
{
    MainPanel();

public:
    static MainPanel &GetInstance();
    ~MainPanel();

    void Draw();
    void Update();
    void SetBars(std::vector<Bar> *bars);
    void GenerateBars(std::vector<Bar> &bars);

    void SetPosition(Vector2 position) { this->m_position = position; }
    void SetSize(Vector2 size) { this->m_size = size; }
    void SetNumberOfBars(int numberOfBars) { this->m_numberOfBars = numberOfBars; }
    void SetNumberOfComparisons(int numberOfComparisons) { this->m_numberOfComparisons = numberOfComparisons; }
    void SetNumberOfSwaps(int numberOfSwaps) { this->m_numberOfSwaps = numberOfSwaps; }
    void SetAlgorithmName(std::string algorithmName) { this->m_algorithmName = algorithmName; }

    void SetStates(State state, WarningStatus warningStatus)
    {
        this->m_state = state;
        this->m_warningStatus = warningStatus;
    }

private:
    Vector2 m_position;
    Vector2 m_size;
    int m_numberOfBars;
    int m_numberOfComparisons;
    int m_numberOfSwaps;

    std::vector<Bar> *m_bars;

    State m_state;
    WarningStatus m_warningStatus;
    WarningStatus m_previousWarningStatus = WarningStatus::None;

    std::string m_algorithmName = "";
};