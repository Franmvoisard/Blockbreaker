#include "GameObject.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

GameObject::GameObject(const Vector2f position, const float rotation, const Vector2f scale, std::unique_ptr<Drawable> drawable)
{
    m_drawable = std::move(drawable);
    setPosition(position);
    setRotation(rotation);
    setScale(scale);
}


GameObject::~GameObject() = default;

void GameObject::Tick()
{
}

void GameObject::draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();
    if(m_drawable)
    {
        target.draw(*m_drawable, states);
    }
}

