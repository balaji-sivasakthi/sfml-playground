#include <SFML/Graphics.hpp>

int main()
{
    int wWidth = 640;
    int wHeight = 400;
    float vX = 0.01f;
    float posX = 0.0f;
    float posY = 0.0f;
    float sx = 0.02f;
    float sy = 0.02f;
    sf::RenderWindow window(sf::VideoMode(640, 400), "My App");
    sf::CircleShape circle;
    circle.setRadius(40.f);
    circle.setPosition(posX, posY);
    circle.setFillColor(sf::Color::Cyan);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        circle.setPosition(circle.getPosition().x + sx, circle.getPosition().y + sy);
        window.clear();
        window.draw(circle);
        window.display();
    }
}