#pragma once
#include <SFML/System/Clock.hpp>

#include "../TextObject.h"

class FpsCounter final : public TextObject
{
    public:
        FpsCounter(const Vector2f& position, const float rotation, const Vector2f& scale);
        void Tick() override;
        ~FpsCounter() override = default;

    private:
        Clock m_clock;
        unsigned short fpsCounter;
        unsigned short fpsCount;
};
