#include "TextObject.h"
#include <SFML/Graphics/Text.hpp>

#include "../GameFramework/FontManager.h"

TextObject::TextObject(const Vector2f& position, float rotation, const Vector2f& scale) : GameObject(position, rotation, scale, *new Text())
{
    m_text = dynamic_cast<Text*>(m_drawable); 
    m_text->setFont(*FontManager::GetDefaultFont());
    m_text->setCharacterSize(24);
    m_text->setFillColor(Color::White);
    m_text->setStyle(Text::Style::Bold);
}

void TextObject::Tick()
{
    GameObject::Tick();
}

void TextObject::UpdateText(const String& text) const
{
    m_text->setString(text);
}

TextObject::~TextObject()
{
    delete m_text;
}