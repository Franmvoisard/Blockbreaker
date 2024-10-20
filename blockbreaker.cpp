#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "GameFramework/GameObject.h"
#include "GameFramework/InputManager.h"
#include "GameFramework/TimeManager.h"
#include "GameObjects/Paddle.h"

unsigned int screenWidth, screenHeight;
Texture textureAtlas = Texture();

int main()
{
    screenWidth = VideoMode::getDesktopMode().width;
    screenHeight = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(screenWidth, screenHeight, 32), "Block breaker");
    
    if(!textureAtlas.loadFromFile("./resources/sprites/spritesheet.png"))
    {
        throw std::runtime_error("Failed to load spritesheet.png");
    }
    const IntRect paddleSprite(0,24,80,16);

    std::unique_ptr<Drawable> sprite = std::make_unique<Sprite>(textureAtlas, paddleSprite);
    std::shared_ptr<GameObject> paddle = std::make_shared<Paddle>(Vector2f(0,0),0,Vector2f(3,3), 800, std::move(sprite));    
    // Render queue to store shapes
    std::vector<std::shared_ptr<GameObject>> renderQueue;
    renderQueue.push_back(paddle);

    // Main game loop
    while (window.isOpen())
    {
        // Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            InputManager::UpdateEvents(event);
        }

        // Clear the window
    
        window.clear();
        TimeManager::update();
        
        // Draw all shapes in the render queue
    
        for (const auto& drawable : renderQueue)
        {
            drawable->Tick();
            window.draw(*drawable);
        }

        // Display the rendered content
        window.display();
    }

    return 0;
}
