#pragma once

#include <thread>
#include <vector>
#include <algorithm>
#include <iostream>

#include <imgui.h>
#include <raylib.h>
#include <rlImGui.h>

#include "Bar/Bar.h"
#include "SidePanel/SidePanel.h"
#include "MainPanel/MainPanel.h"

#include "Algorithms/MergeSort.h"
#include "Algorithms/BubbleSort.h"
#include "Algorithms/InsertionSort.h"
#include "Algorithms/SelectionSort.h"
#include "Algorithms/CocktailSort.h"
#include "Algorithms/HeapSort.h"
#include "Algorithms/ShellSort.h"
#include "Algorithms/QuickSort.h"
#include "Algorithms/GnomeSort.h"
#include "Algorithms/CombSort.h"

#include "Status.h"

class App
{
    App();

public:
    static App &GetInstance();
    ~App();

    void Run();
    void Update();
    void Draw();

private:
    int m_numberOfBars;

    float m_width = 1280;
    float m_height = 720;
    std::vector<Bar> *m_bars;

    SidePanel &m_sidePanel = SidePanel::GetInstance();
    MainPanel &m_mainPanel = MainPanel::GetInstance();

    std::vector<Algorithm *> m_algorithms;

    State m_state;
    WarningStatus m_warningStatus;

    int m_numberOfComparisons = 0;
    int m_numberOfSwaps = 0;

    std::string m_algorithmName = "";
};