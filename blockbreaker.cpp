#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Create a blue square
    sf::RectangleShape blueSquare;
    blueSquare.setSize(sf::Vector2f(50.f, 50.f));  // Set the size of the square (50x50)
    blueSquare.setFillColor(sf::Color::Blue);      // Set the fill color to blue
    blueSquare.setOrigin(0.5 * blueSquare.getSize().x, 0.5f * blueSquare.getSize().y);  // Set origin to a quarter of the width and height
    blueSquare.setPosition(25, 25);              // Set the position of the square

    // Create a yellow square
    sf::RectangleShape yellowSquare;
    yellowSquare.setSize(sf::Vector2f(50.f, 50.f));  // Set the size of the square (50x50)
    yellowSquare.setFillColor(sf::Color::Yellow);     // Set the fill color to yellow
    yellowSquare.setOrigin(0.5f * yellowSquare.getSize().x, 0.5f * yellowSquare.getSize().y);  // Set origin to a quarter of the width and height
    yellowSquare.setPosition(75, 25);               // Set the position of the yellow square

    // Create a green square
    sf::RectangleShape blueSquare2;
    blueSquare2.setSize(sf::Vector2f(50.f, 50.f));   // Set the size of the square (50x50)
    blueSquare2.setFillColor(sf::Color::Blue);       // Set the fill color to green
    blueSquare2.setOrigin(0.5f * blueSquare2.getSize().x, 0.5f * blueSquare2.getSize().y);  // Set origin to a quarter of the width and height
    blueSquare2.setPosition(125, 25);               // Set the position of the green square

    // Render queue to store shapes
    std::vector<std::shared_ptr<sf::Drawable>> renderQueue;
    renderQueue.push_back(std::make_shared<sf::RectangleShape>(blueSquare));
    renderQueue.push_back(std::make_shared<sf::RectangleShape>(yellowSquare));
    renderQueue.push_back(std::make_shared<sf::RectangleShape>(blueSquare2));

    // Main game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw all shapes in the render queue
        for (const auto& drawable : renderQueue)
        {
            window.draw(*drawable);
        }

        // Display the rendered content
        window.display();
    }

    return 0;
}
