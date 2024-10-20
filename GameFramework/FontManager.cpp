#include "FontManager.h"

#include <stdexcept>
sf::Font* FontManager::m_defaultFont = nullptr;

sf::Font* FontManager::GetDefaultFont()
{
    if(m_defaultFont == nullptr)
    {
        m_defaultFont = new sf::Font();
        if(!m_defaultFont->loadFromFile("C:/Windows/Fonts/arial.ttf"))
        {
            throw std::runtime_error("Failed to load font arial.ttf");
        }
    }
    return m_defaultFont;
}