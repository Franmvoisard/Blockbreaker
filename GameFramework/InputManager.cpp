#include "InputManager.h"
#include <unordered_set>

std::unordered_set<sf::Keyboard::Key> InputManager::keyPressed = std::unordered_set<sf::Keyboard::Key>();
std::unordered_set<sf::Keyboard::Key> InputManager::keyReleased = std::unordered_set<sf::Keyboard::Key>();
std::unordered_set<sf::Keyboard::Key> InputManager::keyDown = std::unordered_set<sf::Keyboard::Key>();

bool InputManager::IsKeyPressed(const sf::Keyboard::Key key)
{
    return IsKeyDown(key) || keyPressed.find(key) != keyPressed.end() ;
}

 bool InputManager::IsKeyReleased(const sf::Keyboard::Key key)
{
    return keyReleased.find(key) != keyReleased.end();
}

bool InputManager::IsKeyDown(const sf::Keyboard::Key key)
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
                keyDown.insert(event.key.code);
            }
        }
        else
        {
            if(!IsKeyPressed(event.key.code))
            {
                keyPressed.insert(event.key.code);// Move to pressed
                keyDown.erase(event.key.code);// Remove from down
            }
        }
    }
    else if(event.type == sf::Event::KeyReleased)
    {
        if(!IsKeyReleased(event.key.code))
        {
            keyReleased.insert(event.key.code);
            keyDown.erase(event.key.code);
            keyPressed.erase(event.key.code);        
        }
    }
}