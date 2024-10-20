#include "TimeManager.h"
#include <SFML/System/Clock.hpp>

sf::Clock TimeManager::m_clock = sf::Clock();
float TimeManager::m_deltaTime;
float m_previousElapsedTime;

float TimeManager::getDeltaTime()
{
    return m_deltaTime;    
}

void TimeManager::update()
{
    m_deltaTime = m_clock.restart().asSeconds();
}

