#include "InputManager.h"

#include <iostream>
#include <ostream>
#include <unordered_set>

std::unordered_set<sf::Keyboard::Key> InputManager::keyPressed = std::unordered_set<sf::Keyboard::Key>();
std::unordered_set<sf::Keyboard::Key> InputManager::keyReleased = std::unordered_set<sf::Keyboard::Key>();
std::unordered_set<sf::Keyboard::Key> InputManager::keyDown = std::unordered_set<sf::Keyboard::Key>();

bool InputManager::IsKeyPressed(sf::Keyboard::Key key)
{
    return IsKeyDown(key) || keyPressed.find(key) != keyPressed.end() ;
}

 bool InputManager::IsKeyReleased(sf::Keyboard::Key key)
{
    return keyReleased.find(key) != keyReleased.end();
}

bool InputManager::IsKeyDown(sf::Keyboard::Key key)
{
    return keyDown.find(key) != keyDown.end();
}

void InputManager::UpdateEvents(const sf::Event& event)
{
    keyReleased.clear();
    if(event.type == sf::Event::KeyPressed)
    {
        if(!IsKeyDown(event.key.code))
        {
            if(!IsKeyPressed(event.key.code))
            {
               std::cout << "[InputManager] Key Down: " << event.key.code << std::endl; 
               keyDown.insert(event.key.code);
            }
        }
        else
        {
            if(!IsKeyPressed(event.key.code))
            {
                std::cout << "[InputManager] Key Pressed: " << event.key.code << std::endl; 
                keyPressed.insert(event.key.code);// Move to pressed
                keyDown.erase(event.key.code);// Remove from down
            }
        }
    }
    else if(event.type == sf::Event::KeyReleased)
    {
        if(!IsKeyReleased(event.key.code))
        {
            std::cout << "[InputManager] Key Released: " << event.key.code << std::endl; 
            keyReleased.insert(event.key.code);
            keyDown.erase(event.key.code);
            keyPressed.erase(event.key.code);        
        }
    }
}