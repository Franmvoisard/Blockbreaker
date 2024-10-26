#pragma once
#include "../GameFramework/GameObject.h"

class Paddle final : public GameObject
{
    public:
        Paddle(Vector2f position, float rotation, Vector2f scale, float movement_speed, const std::shared_ptr<Drawable>& drawable);
        void move(float input);
        void Tick() override;
    private:
        float m_speed;
};
