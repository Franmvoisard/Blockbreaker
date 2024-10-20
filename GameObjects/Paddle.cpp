#include "Paddle.h"
#include "../GameFramework/InputManager.h"
#include "../GameFramework/TimeManager.h"

Paddle::Paddle(const Vector2f position, const float rotation, const Vector2f scale, const float movement_speed, Drawable& drawable) : GameObject(position, rotation, scale, drawable)
{
     m_speed = movement_speed;
}

void Paddle::move(const float input)
{
    GameObject::move(input,0);
}

void Paddle::Tick()
{
    //Keep base behavior
    GameObject::Tick();
    const float speed = m_speed * TimeManager::getDeltaTime();
    if(InputManager::IsKeyPressed(Keyboard::Left))
    {
        move(-speed);
    }
    else if(InputManager::IsKeyPressed(Keyboard::Right))
    {
        move(speed);
    }
}
