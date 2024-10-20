#pragma once
#include <unordered_set>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

class InputManager
{
    public:
        static bool IsKeyPressed(sf::Keyboard::Key key);
        static bool IsKeyReleased(sf::Keyboard::Key key);
        static bool IsKeyDown(sf::Keyboard::Key key);
        static void UpdateEvents(const sf::Event& event);

    private:
        static std::unordered_set<sf::Keyboard::Key> keyPressed;
        static std::unordered_set<sf::Keyboard::Key> keyReleased;
        static std::unordered_set<sf::Keyboard::Key> keyDown;
};  
