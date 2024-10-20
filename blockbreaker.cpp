#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "GameFramework/GameObject.h"
#include "GameFramework/InputManager.h"
#include "GameFramework/TimeManager.h"
#include "GameObjects/Paddle.h"
#include "GameObjects/TextObject.h"
#include "GameObjects/Utilities/FpsCounter.h"

unsigned int screenWidth, screenHeight;
Texture textureAtlas = Texture();
Text fpstext = Text();

int main()
{
    screenWidth = VideoMode::getDesktopMode().width;
    screenHeight = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(screenWidth, screenHeight, 32), "Block breaker");
    window.setFramerateLimit(60);
    
    if(!textureAtlas.loadFromFile("./resources/sprites/spritesheet.png"))
    {
        throw std::runtime_error("Failed to load spritesheet.png");
    }
    
    Drawable* sprite = new Sprite(textureAtlas, IntRect (0,24,80,16));
    std::shared_ptr<GameObject> paddle = std::make_shared<Paddle>(Vector2f(screenWidth * 0.5f,screenHeight * 0.9f),0,Vector2f(3,3), 800, *sprite);    
    std::shared_ptr<FpsCounter> fpsCounter = std::make_shared<FpsCounter>(Vector2f(screenWidth * 0.9, 0), 0, Vector2f(1,1));
    std::vector<std::shared_ptr<GameObject>> renderQueue;
    renderQueue.push_back(paddle);
    renderQueue.push_back(fpsCounter);

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
