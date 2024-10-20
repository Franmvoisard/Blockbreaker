#include "FpsCounter.h"


FpsCounter::FpsCounter(const Vector2f& position, const float rotation, const Vector2f& scale) : TextObject(position, rotation, scale)
{
    m_clock = Clock();
}

void FpsCounter::Tick() 
{
    if(m_clock.getElapsedTime().asSeconds() < 0.25f)
    {
        fpsCounter++;
    }
    else
    {
        fpsCount = fpsCounter * 4;
        fpsCounter = 0;
        m_clock.restart();
        m_text -> setString("FPS: " + std::to_string(fpsCount));
    }
    TextObject::Tick();
}
