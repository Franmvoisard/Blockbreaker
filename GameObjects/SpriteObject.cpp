#include "SpriteObject.h"
#include <SFML/Graphics/Sprite.hpp>

SpriteObject::SpriteObject(const Texture& texture, const IntRect& textureRect, const Vector2f& spriteOrigin, const Vector2f& position, float rotation, const Vector2f& scale) : GameObject(position, rotation, scale, std::make_shared<Sprite>(texture))
{
    m_sprite = std::dynamic_pointer_cast<Sprite>(m_drawable);
    m_sprite->setTexture(texture);
    m_sprite->setTextureRect(textureRect);
    m_sprite->setOrigin(spriteOrigin);
}

SpriteObject::~SpriteObject()
{
    GameObject::~GameObject();
}

