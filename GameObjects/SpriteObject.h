#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "../GameFramework/GameObject.h"

class SpriteObject : public GameObject
{
    public:
        SpriteObject(const Texture& texture, const IntRect& textureRect, const Vector2f& spriteOrigin,
                     const Vector2f& position,
                     float rotation, const Vector2f& scale);
    
    private:
        std::shared_ptr<Sprite> m_sprite;
        ~SpriteObject() override;
};