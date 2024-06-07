#pragma once

enum class State
{
    None,
    Sorting,
    Shuffling,
    Shuffled,
    Sorted,
    Unsorted,
    Generating,
    Generated
};

enum class WarningStatus
{
    None,
    TooManyBars,
    TooFewBars,
    StillSorting,
    NoAlgorithmSelected,
    StillShuffling,
    AlreadyShuffled,
    AlreadySorted
};

enum class PlotType
{
    Lines,
    Circles,
};