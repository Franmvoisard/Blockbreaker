#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include "../GameFramework/GameObject.h"

class TextObject : public GameObject
{
    public:
        TextObject(const Vector2f& position, float rotation, const Vector2f& scale);
        void Tick() override;
        void UpdateText(const String& text) const;
        ~TextObject();
    
    protected:
        std::shared_ptr<Text> m_text;
};
