#pragma once

#include <raylib.h>
#include <vector>

#include "../Status.h"

class Bar
{
public:
    Bar();
    ~Bar();

    void Draw();
    void SetPosition(Vector2 position, bool animate = false);
    void SetSize(Vector2 size);
    void SetColor(float value);
    void SetColor(Color color);
    void SetValue(float value);

    float GetValue() { return this->m_value; }
    Vector2 GetPosition() { return this->m_position; }
    Color GetColor() { return this->m_color; }

private:
    Vector2 m_position;
    Vector2 m_size;

    Color m_color;
    float m_value;

    PlotType m_plotType = PlotType::Lines;
};