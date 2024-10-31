#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "GameFramework/DisplayUtilities.h"
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

void ProcessInput(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
            
        InputManager::UpdateEvents(event);
    }
}

void UpdateGameObjects(const std::vector<std::shared_ptr<GameObject>>& renderQueue)
{
    TimeManager::update();
    for (const auto& drawable : renderQueue)
    {
        drawable->Tick();
    }
}

void RenderObjects(RenderWindow& window, const std::vector<std::shared_ptr<GameObject>>& renderQueue)
{
    window.clear();
    for (const auto& drawable : renderQueue)
    {
        window.draw(*drawable);
    }
    window.display();
}

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
    paddleSprite->setOrigin(80 * 0.5f, 16 * 0.5f);
    std::shared_ptr<SpriteObject> background = std::make_shared<SpriteObject>(textureBackground, IntRect (0,0,228,246), Vector2f(-1,-1), DisplayUtilities::GetCenter(), 0 , Vector2f(DisplayUtilities::GetSize().y / 246, DisplayUtilities::GetSize().y / 246));
    std::shared_ptr<GameObject> paddle = std::make_shared<Paddle>(Vector2f(screenWidth * 0.5f,screenHeight * 0.9f),0,Vector2f(3,3), 800, paddleSprite);    
    std::shared_ptr<FpsCounter> fpsCounter = std::make_shared<FpsCounter>(Vector2f(screenWidth * 0.9, 0), 0, Vector2f(1,1));
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    gameObjects.push_back(background);
    gameObjects.push_back(paddle);
    gameObjects.push_back(fpsCounter);
    
    while (window.isOpen())
    {
        ProcessInput(window);
        UpdateGameObjects(gameObjects);
        RenderObjects(window, gameObjects);
    }

    return 0;
}
