#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "GameFramework/GameObject.h"
#include "GameFramework/InputManager.h"
#include "GameFramework/TimeManager.h"
#include "GameObjects/Paddle.h"
#include "GameObjects/SpriteObject.h"
#include "GameObjects/TextObject.h"
#include "GameObjects/Utilities/FpsCounter.h"

unsigned int screenWidth, screenHeight;
Texture textureAtlas = Texture();
Texture textureBackground = Texture();
Text fpstext = Text();

int main()
{
    screenWidth = VideoMode::getDesktopMode().width;
    screenHeight = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(screenWidth, screenHeight, 32), "Block breaker");
    window.setFramerateLimit(60);
    
    if(!textureAtlas.loadFromFile("./resources/sprites/spritesheet.png"))
    {
        throw std::runtime_error("Failed to load main spritesheet");
    }
    if(!textureBackground.loadFromFile("./resources/sprites/background-atlas.png"))
    {
        throw std::runtime_error("Failed to load background spritesheet");
    }
    
    std::shared_ptr<Sprite> paddleSprite = std::make_shared<Sprite>(textureAtlas, IntRect (0,24,80,16));
    paddleSprite->setOrigin(80*0.5f, 16 * 0.5f);
    std::shared_ptr<Sprite> backgroundSpr = std::make_shared<Sprite>(textureBackground, IntRect (0,0,228,246));
    backgroundSpr->setOrigin(228 * 0.5f,246 * 0.5f);
    std::shared_ptr<GameObject> background = std::make_shared<GameObject>(Vector2f(screenWidth * 0.5f,screenHeight * 0.5f),0,Vector2f(screenHeight/246,screenHeight/246), backgroundSpr);
    std::shared_ptr<GameObject> paddle = std::make_shared<Paddle>(Vector2f(screenWidth * 0.5f,screenHeight * 0.9f),0,Vector2f(3,3), 800, paddleSprite);    
    std::shared_ptr<FpsCounter> fpsCounter = std::make_shared<FpsCounter>(Vector2f(screenWidth * 0.9, 0), 0, Vector2f(1,1));
    std::vector<std::shared_ptr<GameObject>> renderQueue;
    renderQueue.push_back(background);
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
