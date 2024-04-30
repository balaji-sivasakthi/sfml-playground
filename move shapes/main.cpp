#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class ShapeComponent
{
public:
    sf::Shape *m_shape;
    std::string m_name;
    int m_sx;
    int m_sy;

    // Constructor
    ShapeComponent(sf::Shape *shape, std::string name, int sx, int sy)
        : m_shape(shape),
          m_name(name),
          m_sx(sx),
          m_sy(sy)
    {
    }
};

class MoveShapes
{
    sf::RenderWindow m_window;
    int m_height;
    int m_width;
    std::vector<ShapeComponent> shapeComponents;

public:
    MoveShapes() {}
    MoveShapes(const std::string &file)
    {
        loadConfig(file);
    }

    void start()
    {
        std::cout << "Move Shapes Started\n";
        update();
    }

    void loadConfig(const std::string &file)
    {
        std::ifstream fin(file);
        int x, y, sx, sy, w, h, radius, font_size;
        int r, g, b;
        std::string type = "";
        std::string shape_name = "";
        sf::Font font;
        std::string m_font_file;
        sf::Color font_color;

        for (std::string line; std::getline(fin, line);)
        {
            std::istringstream iss(line);
            while (iss >> type)
            {
                if (type == "Window")
                {
                    iss >> m_width >> m_height;
                    m_window.create(sf::VideoMode(m_width, m_height), "Movement Window");
                    m_window.setFramerateLimit(30);
                }
                else if (type == "Circle")
                {
                    iss >> shape_name >> x >> y >> sx >> sy >> r >> g >> b >> radius;
                    sf::CircleShape *circle = new sf::CircleShape(radius);
                    circle->setPosition(x, y);
                    circle->setFillColor(sf::Color(r, g, b));
                    ShapeComponent scircle(circle, shape_name, sx, sy);
                    shapeComponents.push_back(scircle);
                }
                else if (type == "Rectangle")
                {
                    iss >> shape_name >> x >> y >> sx >> sy >> r >> g >> b >> w >> h;
                    sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(w, h));
                    rect->setPosition(x, y);
                    rect->setFillColor(sf::Color(r, g, b));
                    ShapeComponent srect(rect, shape_name, sx, sy);
                    shapeComponents.push_back(srect);
                }
            }
        }
    }

    void update()
    {

        while (m_window.isOpen())
        {
            sf::Event event;

            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window.close();
                }
            }
            m_window.clear();
            render();
            m_window.display();
        }
    }
    void render()
    {
        // TODO: Collision with window not working as expected
        for (ShapeComponent &component : shapeComponents)
        {
            sf::Shape *local_shape = component.m_shape;
            float vx = component.m_sx;
            float vy = component.m_sy;
            sf::Vector2f pos = local_shape->getPosition();
            sf::FloatRect shape_bounds = local_shape->getGlobalBounds();
            if (pos.x <= 0 || pos.x + shape_bounds.width >= m_width)
            {
                component.m_sx *= -1;
            }
            if (pos.y <= 0 || pos.y + shape_bounds.height >= m_height)
            {
                component.m_sy *= -1;
            }
            local_shape->move(vx, vy);
            m_window.draw(*local_shape);
        }
    }
};

int main()
{
    const std::string file_path = "config.txt";
    MoveShapes move_shapes(file_path);
    move_shapes.start();
    return 0;
}
