#include "Bar.h"

#include <iostream>

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::Draw()
{
    if (this->m_plotType == PlotType::Circles)
    {
        // use value as angle to draw circle
        // postion is center of circle and size is radius

        DrawRectanglePro(
            Rectangle{
                this->m_position.x,
                this->m_position.y,
                this->m_size.x,
                this->m_size.y},
            Vector2{this->m_size.x / 2, this->m_size.y / 2},
            this->m_value,
            this->m_color);

        return;
    }
    DrawLineEx(this->m_position, Vector2{this->m_position.x, this->m_position.y - this->m_size.y}, this->m_size.x, this->m_color);
}

void Bar::SetPosition(Vector2 position, bool animate)
{
    if (animate)
    {
        float targetPosition = position.x;
        float currentPosition = this->m_position.x;
        float distance = targetPosition - currentPosition;
        float speed = 0.05f;
        while (currentPosition != targetPosition)
        {
            if (currentPosition < targetPosition)
            {
                currentPosition += speed;
                if (currentPosition > targetPosition)
                {
                    currentPosition = targetPosition;
                }
            }
            else
            {
                currentPosition -= speed;
                if (currentPosition < targetPosition)
                {
                    currentPosition = targetPosition;
                }
            }
            this->m_position.x = currentPosition;
        }
        return;
    }

    this->m_position = position;
}

void Bar::SetSize(Vector2 size)
{
    this->m_size = size;
}

void Bar::SetColor(float value)
{
    this->m_color = ColorFromHSV(value * 255.0f, 1.0f, 1.0f);
}

void Bar::SetColor(Color color)
{
    this->m_color = color;
}

void Bar::SetValue(float value)
{
    this->m_value = value;
    if (this->m_plotType == PlotType::Lines)
    {
        this->SetPosition(Vector2{value, this->m_position.y}, true);
    }
}