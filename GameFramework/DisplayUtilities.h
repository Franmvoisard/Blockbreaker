#pragma once
#include <SFML/System/Vector2.hpp>

class DisplayUtilities
{
public:
    DisplayUtilities();
    static sf::Vector2f GetCenter();
    static sf::Vector2u GetSize();
};
