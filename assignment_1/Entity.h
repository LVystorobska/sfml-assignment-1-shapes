#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
public:
    sf::CircleShape circle;
    sf::RectangleShape rectangle;
    float speedX;
    float speedY;
    std::string stype;
    std::string sname;

    Entity() {}
    Entity(std::string type, std::string name, float sx, float sy)
    : stype(type), sname(name), speedX(sx), speedY(sy) {}

};
