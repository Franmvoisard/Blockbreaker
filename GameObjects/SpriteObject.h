#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "../GameFramework/GameObject.h"

class SpriteObject : public GameObject
{
    public:
        SpriteObject(const Texture& texture, const IntRect& textureRect, const Vector2f& spriteOrigin = Vector2f(-1, -1),
                 const Vector2f& position = Vector2f(0, 0),
                 float rotation = 0, const Vector2f& scale = Vector2f(1, 1));
        ~SpriteObject() override;
    
    private:
        std::shared_ptr<Sprite> m_sprite;
        void AdjustOrigin(const IntRect& textureRect, const Vector2f& spriteOrigin) const;
};