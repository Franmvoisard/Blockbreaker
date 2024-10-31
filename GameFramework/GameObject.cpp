#include "GameObject.h"

#include <SFML/Graphics/RenderTarget.hpp>

GameObject::GameObject(const std::shared_ptr<Drawable>& drawable, const Vector2f position, const float rotation, const Vector2f scale)
{
    m_drawable = drawable;
    setPosition(position);
    setRotation(rotation);
    setScale(scale);
}

GameObject::~GameObject()
{
    Drawable::~Drawable();
    Transformable::~Transformable();
}

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

