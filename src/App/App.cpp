#include "App.h"

App::App()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(this->m_width, this->m_height, "Sorting Visualizer");
    SetTargetFPS(60);
    rlImGuiSetup(true);
    SetExitKey(0);

    this->m_algorithms.push_back(&MergeSort::GetInstance());
    this->m_algorithms.push_back(&BubbleSort::GetInstance());
    this->m_algorithms.push_back(&InsertionSort::GetInstance());
    this->m_algorithms.push_back(&SelectionSort::GetInstance());
    this->m_algorithms.push_back(&CocktailSort::GetInstance());
    this->m_algorithms.push_back(&HeapSort::GetInstance());
    this->m_algorithms.push_back(&ShellSort::GetInstance());
    this->m_algorithms.push_back(&QuickSort::GetInstance());
    this->m_algorithms.push_back(&GnomeSort::GetInstance());
    this->m_algorithms.push_back(&CombSort::GetInstance());

    this->m_bars = new std::vector<Bar>();

    this->m_sidePanel.SetPosition(Vector2{0, 0});
    this->m_sidePanel.SetSize(Vector2{GetScreenWidth() * 0.25f, (float)GetScreenHeight()});
    this->m_sidePanel.SetAlgorithms(&this->m_algorithms);
    this->m_sidePanel.SetBars(this->m_bars);
    this->m_sidePanel.SetNumberOfBars(this->m_numberOfBars);
    this->m_sidePanel.SetStates(this->m_state, this->m_warningStatus);

    this->m_mainPanel.SetPosition(Vector2{GetScreenWidth() * 0.25f, 0});
    this->m_mainPanel.SetSize(Vector2{(float)GetScreenWidth() * 0.75f, (float)GetScreenHeight()});
    this->m_mainPanel.SetStates(this->m_state, this->m_warningStatus);

    std::function<void()> generateBarsFunctions = [this]()
    {
        std::vector<Bar> *bars = this->m_bars;
        this->m_sidePanel.SetNumberOfBars(this->m_numberOfBars);

        std::thread t(
            [this, bars]()
            {
                this->m_mainPanel.SetNumberOfBars(this->m_numberOfBars);
                this->m_mainPanel.GenerateBars(*bars);
                this->m_mainPanel.SetBars(bars);
            });

        t.detach();
    };

    this->m_sidePanel.SetGenerateBarsFunction(generateBarsFunctions);

    std::function<void()> shuffle = [this]()
    {
        std::thread t(
            [this]()
            {
                for (int i = 0; i < this->m_numberOfBars; i++)
                {
                    int randomIndex = GetRandomValue(i, this->m_numberOfBars - 1);

                    // std::swap(this->m_bars->at(i), this->m_bars->at(j));
                    while (i == randomIndex)
                    {
                        randomIndex = GetRandomValue(0, this->m_numberOfBars - 1);
                    }

                    float tempValue = this->m_bars->at(i).GetValue();
                    this->m_bars->at(i).SetValue(this->m_bars->at(randomIndex).GetValue());
                    this->m_bars->at(randomIndex).SetValue(tempValue);
                }
            });

        t.detach();
    };

    this->m_sidePanel.SetShuffleFunction(shuffle);
}

App::~App()
{
    CloseWindow();
}

App &App::GetInstance()
{
    static App instance;
    return instance;
}

void App::Run()
{
    while (!WindowShouldClose())
    {
        this->Update();
        this->Draw();
    }
}

void App::Update()
{
    this->m_sidePanel.SetStates(this->m_state, this->m_warningStatus);
    this->m_mainPanel.SetStates(this->m_state, this->m_warningStatus);
    if (IsWindowResized())
    {
        float width = GetScreenWidth();
        float height = GetScreenHeight();

        this->m_sidePanel.SetSize(Vector2{width * 0.25f, (float)height});
        this->m_mainPanel.SetPosition(Vector2{width * 0.25f, 0});
        this->m_mainPanel.SetSize(Vector2{width * 0.75f, (float)height});

        this->m_mainPanel.Update();
    }

    this->m_sidePanel.SetNumberOfComparisons(this->m_numberOfComparisons);
    this->m_sidePanel.SetNumberOfSwaps(this->m_numberOfSwaps);
    this->m_sidePanel.SetAlgorithmName(this->m_algorithmName);

    this->m_mainPanel.SetNumberOfComparisons(this->m_numberOfComparisons);
    this->m_mainPanel.SetNumberOfSwaps(this->m_numberOfSwaps);
    this->m_mainPanel.SetAlgorithmName(this->m_algorithmName);
}

void App::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    rlImGuiBegin();

    this->m_sidePanel.Draw();

    rlImGuiEnd();

    this->m_mainPanel.Draw();

    EndDrawing();
}
