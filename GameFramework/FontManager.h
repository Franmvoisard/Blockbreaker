#pragma once
#include <SFML/Graphics/Font.hpp>

class FontManager
{
    public:
        static sf::Font* GetDefaultFont();
    private:
        static sf::Font* m_defaultFont;
};
