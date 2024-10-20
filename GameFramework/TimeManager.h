#pragma once
#include <SFML/System/Clock.hpp>

class TimeManager
{
    public:
        static float getDeltaTime();
        static void update();

    private:
        static sf::Clock m_clock;
        static float m_deltaTime;
};
