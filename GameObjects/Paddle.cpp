#include "Paddle.h"

#include <iostream>
#include <ostream>

#include "../GameFramework/InputManager.h"
#include "../GameFramework/TimeManager.h"

Paddle::Paddle(Vector2f position, float rotation, Vector2f scale, const float movement_speed, std::unique_ptr<Drawable> drawable) : GameObject(position, rotation, scale, std::move(drawable))
{
     m_speed = movement_speed;
}

void Paddle::move(const float input)
{
    GameObject::move(input,0);
    std::cout << getPosition().x << ", " << getPosition().y << std::endl;
}

void Paddle::Tick()
{
    //Keep base behavior
    GameObject::Tick();
    float speed = m_speed * TimeManager::getDeltaTime();
    if(InputManager::IsKeyPressed(Keyboard::Left))
    {
        move(-speed);
    }
    else if(InputManager::IsKeyPressed(Keyboard::Right))
    {
        move(speed);
    }
}
