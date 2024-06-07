#pragma once

#include <raylib.h>
#include <imgui.h>
#include <thread>
#include <functional>
#include <vector>

#include "../Bar/Bar.h"
#include "../Algorithms/Algorithm.h"
#include "../Status.h"

class SidePanel
{
    SidePanel();

public:
    static SidePanel &GetInstance();
    ~SidePanel();

    void Draw();

    void SetShuffleFunction(std::function<void()> function) { this->m_shuffleFunction = function; }
    void SetPosition(Vector2 position) { this->m_position = position; }
    void SetSize(Vector2 size) { this->m_size = size; }
    void SetBars(std::vector<Bar> *bars) { this->m_bars = bars; }
    void SetAlgorithms(std::vector<Algorithm *> *algorithms) { this->m_algorithms = algorithms; }
    void SetGenerateBarsFunction(std::function<void()> function) { this->m_generateBarsFunction = function; }
    void SetNumberOfBars(int &numberOfBars) { numberOfBars = *this->m_numberOfBars; }
    void SetNumberOfComparisons(int &numberOfComparisons) { numberOfComparisons = this->m_numberOfComparisons; }
    void SetNumberOfSwaps(int &numberOfSwaps) { numberOfSwaps = this->m_numberOfSwaps; }
    void SetAlgorithmName(std::string &algorithmName) { algorithmName = this->m_algorithmName; }

    void SetStates(State &state, WarningStatus &warningStatus)
    {
        state = this->m_state;
        warningStatus = this->m_warningStatus;
    }

private:
    Vector2 m_position;
    Vector2 m_size;

    std::function<void()> m_shuffleFunction;
    std::function<void()> m_generateBarsFunction;

    Algorithm *m_selectedAlgorithm = nullptr;

    std::string m_algorithmDropdown = "Select an algorithm";

    std::vector<Algorithm *> *m_algorithms = nullptr;

    std::vector<Bar> *m_bars = nullptr;

    int *m_numberOfBars;

    State m_state = State::None;
    WarningStatus m_warningStatus = WarningStatus::None;

    float m_warningStatusTimer = 0.0f;
    int m_numberOfComparisons = 0;
    int m_numberOfSwaps = 0;
    std::string m_algorithmName = "";
};