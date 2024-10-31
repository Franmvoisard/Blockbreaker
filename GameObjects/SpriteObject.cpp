#include "SpriteObject.h"
#include <SFML/Graphics/Sprite.hpp>

SpriteObject::SpriteObject(const Texture& texture, const IntRect& textureRect, const Vector2f& spriteOrigin, const Vector2f& position, float rotation, const Vector2f& scale) : GameObject(std::make_shared<Sprite>(texture), position, rotation, scale)
{
    m_sprite = std::dynamic_pointer_cast<Sprite>(m_drawable);
    m_sprite->setTexture(texture);
    m_sprite->setTextureRect(textureRect);
    AdjustOrigin(textureRect, spriteOrigin);
}

void SpriteObject::AdjustOrigin(const IntRect& textureRect, const Vector2f& spriteOrigin) const
{
    if(spriteOrigin.x == -1 && spriteOrigin.y == -1)
    {
        m_sprite->setOrigin(textureRect.width * 0.5f, textureRect.height * 0.5f);
    }
    else
    {
        m_sprite->setOrigin(spriteOrigin);
    }
}

SpriteObject::~SpriteObject()
{
    GameObject::~GameObject();
}

