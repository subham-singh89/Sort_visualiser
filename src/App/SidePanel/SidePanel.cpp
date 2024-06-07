#include "SidePanel.h"

#include <iostream>

SidePanel::SidePanel()
{
    this->m_numberOfBars = new int;
}

SidePanel::~SidePanel()
{
}

SidePanel &SidePanel::GetInstance()
{
    static SidePanel instance;
    return instance;
}

void SidePanel::Draw()
{
    ImGui::SetNextWindowPos({this->m_position.x, this->m_position.y});
    ImGui::SetNextWindowSize({this->m_size.x, this->m_size.y});
    ImGui::Begin("Side Panel", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

    ImGui::AlignTextToFramePadding();
    ImGui::Text("Number of bars: ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
    if (ImGui::InputInt("Number of bars", this->m_numberOfBars, 0, 0, ImGuiInputTextFlags_CharsDecimal))
    {
        if (*this->m_numberOfBars < 1000)
        {
            *this->m_numberOfBars = 1000;
            this->m_warningStatus = WarningStatus::TooFewBars;
        }
        else if (*this->m_numberOfBars > 100000)
        {
            *this->m_numberOfBars = 100000;
            this->m_warningStatus = WarningStatus::TooManyBars;
        }
    }

    if (ImGui::Button("Generate", ImVec2(ImGui::GetContentRegionAvail().x, 0)))
    {
        if (this->m_generateBarsFunction != nullptr)
        {
            this->m_state = State::Generating;
            this->m_generateBarsFunction();
            this->m_state = State::Generated;
        }
    }

    if (ImGui::Button("Shuffle", ImVec2(ImGui::GetContentRegionAvail().x, 0)))
    {
        if (this->m_state == State::Shuffling)
        {
            this->m_warningStatus = WarningStatus::StillShuffling;
        }
        else if (this->m_state == State::Shuffled)
        {
            this->m_warningStatus = WarningStatus::AlreadyShuffled;
        }
        else if (this->m_shuffleFunction != nullptr)
        {
            this->m_state = State::Shuffling;
            this->m_shuffleFunction();
            this->m_state = State::Shuffled;
        }
    }

    if (this->m_algorithms != nullptr)
    {
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
        if (ImGui::BeginCombo("##Algorithm", this->m_algorithmDropdown.c_str()))
        {
            for (auto algorithm : *this->m_algorithms)
            {
                bool isSelected = (this->m_algorithmDropdown == algorithm->GetName());
                if (ImGui::Selectable(algorithm->GetName().c_str(), isSelected))
                {
                    this->m_algorithmDropdown = algorithm->GetName();
                    this->m_selectedAlgorithm = algorithm;
                    this->m_algorithmName = algorithm->GetName();
                }
                if (isSelected)
                    ImGui::SetItemDefaultFocus();
            }

            ImGui::EndCombo();
        }
    }

    if (ImGui::Button("Sort", ImVec2(ImGui::GetContentRegionAvail().x / 2, 0)))
    {
        if (this->m_selectedAlgorithm == nullptr || this->m_state == State::Sorting || this->m_state == State::Sorted)
        {
            if (this->m_state == State::Sorting)
                this->m_warningStatus = WarningStatus::StillSorting;
            else if (this->m_state == State::Sorted)
                this->m_warningStatus = WarningStatus::AlreadySorted;
            else
                this->m_warningStatus = WarningStatus::NoAlgorithmSelected;

            ImGui::End();
            return;
        }

        std::thread t(
            [this]()
            {
                if (this->m_selectedAlgorithm != nullptr)
                {
                    this->m_state = State::Sorting;
                    this->m_selectedAlgorithm->Sort(*this->m_bars);
                    this->m_state = State::Sorted;
                }
            });

        t.detach();
    }

    if (this->m_warningStatus != WarningStatus::None)
    {
        this->m_warningStatusTimer += GetFrameTime();
        if (this->m_warningStatusTimer >= 2.5f)
        {
            this->m_warningStatus = WarningStatus::None;
            this->m_warningStatusTimer = 0.0f;
        }
    }

    ImGui::End();

    if (this->m_state == State::Sorting)
    {
        this->m_selectedAlgorithm->SetNumberOfComparisons(this->m_numberOfComparisons);
        this->m_selectedAlgorithm->SetNumberOfSwaps(this->m_numberOfSwaps);
    }
}