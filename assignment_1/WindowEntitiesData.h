#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"


class WindowEntitiesData {

public:
    int wWidth;
    int wHeight;
    int fSize;
    int fr, fg, fb;
    sf::Font font;
    std::vector<Entity> shapes;

    WindowEntitiesData() {}

    void loadFromFile(const std::string& filename);
};
