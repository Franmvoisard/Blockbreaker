#include "DisplayUtilities.h"

#include <SFML/Window/VideoMode.hpp>

DisplayUtilities::DisplayUtilities()= default;

sf::Vector2f DisplayUtilities::GetCenter()
{
    return {static_cast<float>(GetSize().x) / 2, static_cast<float> (GetSize().y) / 2} ;
}

sf::Vector2u DisplayUtilities::GetSize()
{
    return {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};
}
